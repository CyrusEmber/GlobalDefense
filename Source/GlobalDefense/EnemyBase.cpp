// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
#include "TurretPawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	}

	// Create StaticMesh component for turrent
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	Initialization();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*FindTarget();*/
	Move();
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBase::Initialization()
{
	FindTarget();
	GetMovingDirection();
}

void AEnemyBase::Move()
{
	// Calculate the new location by moving with a constant speed in that direction
	FVector NewLocation = GetActorLocation() + Direction * Speed * GetWorld()->GetDeltaSeconds();

	// Set the new location
	SetActorLocation(NewLocation);
}

void AEnemyBase::FindTarget()
{
	TSubclassOf<ATurretPawn> ClassToFind = ATurretPawn::StaticClass();
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Actors numbers: %d"), FoundActors.Num()));
	for (AActor* Actor : FoundActors) {
		ATurretPawn* Turret = Cast<ATurretPawn>(Actor);
		if (Turret) {
			Target = Turret;
		}
		break;
	}
	//if (!Target) {
	//	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("No target for enemy")));
	//}
}

void AEnemyBase::GetMovingDirection()
{
	if (Target) {
		Direction = (Target->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	}
	
}

