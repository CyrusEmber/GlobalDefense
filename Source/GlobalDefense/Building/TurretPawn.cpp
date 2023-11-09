// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPawn.h"
#include "Components/SphereComponent.h"
#include "../EnemyBase.h"
#include "../BulletBase.h"

// Sets default values
ATurretPawn::ATurretPawn()
{
	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	}
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create StaticMesh component for turrent
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent"));
	TurretMesh->SetupAttachment(RootComponent);
	TurretMesh->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	TurretMesh->SetCollisionProfileName(TEXT("Pawn"));

	// Create Trigger Volume
	TriggerVolume = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerVolume"));
	TriggerVolume->SetupAttachment(RootComponent);

	TriggerVolume->InitSphereRadius(Range);
	TriggerVolume->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	TriggerVolume->SetGenerateOverlapEvents(true);

	// Set collision channel
	TriggerVolume->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	TriggerVolume->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	TriggerVolume->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Overlap);


}

TurretInfo ATurretPawn::GetTurretInfo()
{
	TurretInfo Info;
	Info.Type = Type;
	Info.Damage = TurretDamage;
	Info.Range = Range;
	Info.FireRate = FireRate;
	Info.Cost = Cost;
	Info.HealthRatio = CurrentHealth / MaxHealth;  // Assuming you have a CurrentHealth member in ATurretPawn

	return Info;
}

FString ATurretPawn::GetType()
{
	return Type;
}

float ATurretPawn::GetDamage()
{
	return TurretDamage;
}

float ATurretPawn::GetRange()
{
	return Range;
}

float ATurretPawn::GetFireRate()
{
	return FireRate;
}

float ATurretPawn::GetHealthRatio()
{
	return CurrentHealth / MaxHealth;
}

int ATurretPawn::GetCost()
{
	return Cost;
}

// Called when the game starts or when spawned
void ATurretPawn::BeginPlay()
{
	Super::BeginPlay();
	// Apply Upgrades
	UpgradeBySkillTree();

	// Setup Trigger Volume
	if (TriggerVolume)
	{
		//TriggerVolume->SetSphereRadius(200.f);
		//FCollisionShape shape = TriggerVolume->GetCollisionShape();

		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATurretPawn::TriggerEnter);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATurretPawn::OnOverlapEnd);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not create TriggerVolume for Pawn %s"), *this->GetName());
	}


	//TurretMesh->SetMaterial(0, OverlayMaterial);
}

void ATurretPawn::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString ActorName = OtherActor->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Entered %s"), *ActorName));
	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if (Enemy) {
		EnemiesInRange.AddUnique(Enemy); // Make sure we only add unique instances

		// If this is the first enemy, start firing
		if (EnemiesInRange.Num() == 1) {
			StartFiring();
		}
	}

}

void ATurretPawn::OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	FString ActorName = OtherActor->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Left %s"), *ActorName));

	AEnemyBase* Enemy = Cast<AEnemyBase>(OtherActor);
	if (Enemy) {
		EnemiesInRange.RemoveSingle(Enemy); // Remove the enemy from the array

		// If there are no more enemies, stop firing
		if (EnemiesInRange.Num() == 0) {
			StopFiring();
		}
	}
}

// Called every frame
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//FCollisionShape shape = TriggerVolume->GetCollisionShape();
	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Radius %f"), shape.GetSphereRadius()));
}

// Called to bind functionality to input
void ATurretPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurretPawn::RotateTurretTowardsTarget()
{
}

// The turret is spawn in the correct x, y location, but Z location is not correct. X, Y position is on the ground now.
// Pivot point of the mesh is at its center rather than its base
void ATurretPawn::Initialization()
{
	// Set the spawn parameters, such as location and rotation
	FVector MeshCenterPosition = TurretMesh->GetComponentLocation();
	FBox MeshBox = TurretMesh->Bounds.GetBox();
	FVector Extents = MeshBox.GetExtent(); // Gets half of the +binding box
	if (RootComponent) {
		FVector NewLocation = RootComponent->GetComponentLocation();
		NewLocation += FVector(0.0f, 0.0f, Extents.Z);
		RootComponent->SetWorldLocation(NewLocation);
		ActorLocationZ = NewLocation.Z;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("No root component")));
	}
}

void ATurretPawn::ShowRange()
{
	if (TriggerVolume)
	{
		// Get the location and radius of the sphere
		FVector SphereLocation = TriggerVolume->GetComponentLocation();
		float SphereRadius = TriggerVolume->GetUnscaledSphereRadius();

		// Set the color and duration for debugging purposes
		FColor DebugColor = FColor::Green;
		float DebugDuration = 5.0f;  // Adjust the duration as needed

		// Draw the sphere
		DrawDebugSphere(GetWorld(), SphereLocation, SphereRadius, 32, DebugColor, false, DebugDuration);
	}
}

void ATurretPawn::ShowDebug()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("No root component")));
}

void ATurretPawn::SetRedOverlay()
{
	if (TurretMesh) {
		TurretMesh->SetOverlayMaterial(RedOverlayMaterial);
	}
}

void ATurretPawn::SetGreenOverlay()
{
	if (TurretMesh) {
		TurretMesh->SetOverlayMaterial(GreenOverlayMaterial);
	}
}

void ATurretPawn::ResetOverlay()
{
	if (TurretMesh) {
		TurretMesh->SetOverlayMaterial(nullptr);
	}
}

void ATurretPawn::UpdatePlacementOverlay(const FVector& NewLocation)
{
}

FVector ATurretPawn::FindTargetEnemyLocation()
{
	int32 RandomIndex = FMath::RandRange(0, EnemiesInRange.Num() - 1);

	// Access the enemy at the random index
	AEnemyBase* RandomEnemy = EnemiesInRange[RandomIndex];

	return RandomEnemy->GetActorLocation();
}

// Not used
bool ATurretPawn::IsEnemyInRange()
{
	if (EnemiesInRange.Num() > 0) {
		return true;
	}
	else {
		return false;
	}
}

void ATurretPawn::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Firing!")));
	UWorld* const World = GetWorld();
	// Location from the turret mesh or root component
	FVector SpawnLocation = TurretMesh ? TurretMesh->GetComponentLocation() : GetActorLocation();
	SpawnLocation.Z += 300.f;

	// Forward direction that the turret is facing
	FVector FireDirection = (FindTargetEnemyLocation() - SpawnLocation).GetSafeNormal();

	ABulletBase* SpawnedBullet = SpawnBullet(SpawnLocation, FireDirection);

}

// Spawn and launch the bullet
ABulletBase* ATurretPawn::SpawnBullet(const FVector& SpawnLocation, const FVector& LaunchDirection)
{
	UWorld* World = GetWorld();
	if (World) {
		FActorSpawnParameters SpawnParams;
		// Keep track of who should be credited for any damage, 
		SpawnParams.Instigator = this;

		// Set up the initial location and rotation for the new actor
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(SpawnLocation);
		// Calculate rotation from the LaunchDirection
		FRotator SpawnRotation = LaunchDirection.Rotation();

		ABulletBase* Bullet = World->SpawnActor<ABulletBase>(BulletClass, SpawnLocation, SpawnRotation, SpawnParams);
		if (Bullet)
		{
			// Bullet initialization
			Bullet->Launch(LaunchDirection);
			Bullet->SetLifeSpan(5.0f);
		}

		return Bullet;
	}
	else {
		return nullptr;
	}
}


void ATurretPawn::StartFiring()
{
	if (FireRate > 0)
	{
		GetWorld()->GetTimerManager().SetTimer(FiringTimer, this, &ATurretPawn::Fire, FireRate, true, -0.f);
	}
}

void ATurretPawn::StopFiring()
{
	GetWorld()->GetTimerManager().ClearTimer(FiringTimer);
}

void ATurretPawn::UpgradeInGame()
{

}

void ATurretPawn::UpgradeBySkillTree()
{
	/**
	* Upgrade the turret based on the saved data.
	*/
}

