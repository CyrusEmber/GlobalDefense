// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Building/TurretPawn.h"
#include "EnemyBase.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABulletBase::ABulletBase()
{
    // The bReplicates variable tells the game that this Actor should replicate. 
    // By default, the Actor would only exist locally on the machine that spawns it. 
    // With bReplicates set to True, as long as an authoritative copy of the Actor exists on the server, 
    // it will try to replicate the Actor to all connected clients.
    bReplicates = true;


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Hitbox = CreateDefaultSubobject<USphereComponent>(TEXT("HitBox"));
    RootComponent = Hitbox;
    Hitbox->InitSphereRadius(37.5f);
    Hitbox->SetCollisionProfileName(TEXT("BlockAllDynamic"));
    //BulletHitBox->SetNotifyRigidBodyCollision(true);
    //BulletHitBox->SetSimulatePhysics(true);

    //BulletHitBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    //BulletHitBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
    //Hitbox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    //Hitbox->SetGenerateOverlapEvents(true);

    // Set collision channel
    //Hitbox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
    //Hitbox->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
    //Hitbox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);
    

    // Debug Static mesh
    BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
    BulletMesh->SetupAttachment(RootComponent);
    BulletMesh->SetRelativeScale3D(FVector(0.6, 0.6, 0.6));

    // Setup ProjectileMovement
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->SetUpdatedComponent(RootComponent);
    ProjectileMovement->InitialSpeed = 1000.f;
    ProjectileMovement->MaxSpeed = 1000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = false;
    // Enable gravity by default if you want the projectile to be affected by it
    ProjectileMovement->ProjectileGravityScale = 0.f;

    // Enable projectile bouncing
    //ProjectileMovement->bShouldBounce = true;
    //ProjectileMovement->Bounciness = 0.3f; // Adjust as necessary
    //ProjectileMovement->Friction = 0.2f;

    // Setup ExplosionEffect UParticleSystem
    ExplosionEffect = CreateDefaultSubobject<UParticleSystem>(TEXT("ExplosionEffect"));

    DamageType = UDamageType::StaticClass();
    Damage = 10.0f;
}

void ABulletBase::TriggerEnter(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
    if (Enemy) {
        Enemy->SimpleTakeDamage(BulletDamage);
        Destroy();
    }
}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
    // Setup Trigger Volume
    //if (Hitbox)
    //{
    //    Hitbox->OnComponentBeginOverlap.AddDynamic(this, &ABulletBase::TriggerEnter);
    //}

    //Registering the Projectile Impact function on a Hit event.
    if (GetLocalRole() == ROLE_Authority)
    {
        Hitbox->OnComponentHit.AddDynamic(this, &ABulletBase::OnProjectileImpact);
    }
    //BulletHitBox->OnComponentHit.AddDynamic(this, &ABulletBase::OnHit);
}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletBase::Initialization()
{
}

void ABulletBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
    //ATurretPawn* Turret = Cast<ATurretPawn>(OtherActor);
    AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Bullet hit enemy")));
    if (Enemy) {
        Enemy->SimpleTakeDamage(BulletDamage);
        Destroy();
    }
}

void ABulletBase::Spawn(const FVector& SpawnLocation, const FVector& LaunchDirection, APawn* InstigatorPawn)
{

}

void ABulletBase::Destroyed()
{
    FVector spawnLocation = GetActorLocation();
    UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
}

void ABulletBase::OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Bullet hit enemy")));
    if (Enemy) {
        UGameplayStatics::ApplyPointDamage(OtherActor, Damage, NormalImpulse, Hit, GetInstigator()->Controller, this, DamageType);
        Enemy->SimpleTakeDamage(BulletDamage);
        Destroy();
    }
}

void ABulletBase::Launch(const FVector& LaunchDirection)
{
    if (ProjectileMovement)
    {
        ProjectileMovement->Velocity = LaunchDirection * ProjectileMovement->InitialSpeed;
    }
}

