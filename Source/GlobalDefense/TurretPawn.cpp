// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretPawn.h"
#include "Components/SphereComponent.h"

// Sets default values
ATurretPawn::ATurretPawn()
{
	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	}
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create StaticMesh component for turrent
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turrent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	// Create Trigger Volume
	TriggerVolume = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerVolume"));
	TriggerVolume->SetupAttachment(RootComponent);

	TriggerVolume->InitSphereRadius(Range);
	TriggerVolume->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	TriggerVolume->SetGenerateOverlapEvents(true);


}

TurretInfo ATurretPawn::GetTurretInfo()
{
	TurretInfo Info;
	Info.Type = Type;
	Info.Damage = Damage;
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
	return Damage;
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

		FCollisionShape shape = TriggerVolume->GetCollisionShape();
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Left %f"), shape.GetSphereRadius()));
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ATurretPawn::TriggerEnter);
		TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &ATurretPawn::OnOverlapEnd);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not create TriggerVolume for Pawn %s"), *this->GetName());
	}


	
}

void ATurretPawn::TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString ActorName = OtherActor->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Entered %s"), *ActorName));
}

void ATurretPawn::OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	FString ActorName = OtherActor->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::Printf(TEXT("Left %s"), *ActorName));
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
void ATurretPawn::Initialization()
{
	// Set the spawn parameters, such as location and rotation
	FVector MeshCenterPosition = StaticMeshComponent->GetComponentLocation();
	FBox MeshBox = StaticMeshComponent->Bounds.GetBox();
	FVector Extents = MeshBox.GetExtent(); // Gets half of the +binding box
	if (RootComponent) {
		FVector NewLocation = RootComponent->GetComponentLocation();
		NewLocation += FVector(0.0f, 0.0f, Extents.Z);
		RootComponent->SetWorldLocation(NewLocation);
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

