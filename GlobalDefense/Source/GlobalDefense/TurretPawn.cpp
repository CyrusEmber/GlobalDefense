// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPawn.h"
#include "Components/SphereComponent.h"

// Sets default values
ATurretPawn::ATurretPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create StaticMesh component for turrent
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	// Create Trigger Volume
	TriggerVolume = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerVolume"));
	TriggerVolume->SetupAttachment(RootComponent);

	TriggerVolume->SetGenerateOverlapEvents(true);


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
		TriggerVolume->InitSphereRadius(Range);
		TriggerVolume->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not create TriggerVolume for Pawn %s"), *this->GetName());
	}

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATurretPawn::TriggerEnter);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATurretPawn::OnOverlapEnd);
	
}

void ATurretPawn::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ATurretPawn::OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called every frame
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurretPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurretPawn::RotateTurretTowardsTarget()
{
}

void ATurretPawn::FindTargetEnemy()
{
}

void ATurretPawn::Fire()
{
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

