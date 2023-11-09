// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "../BulletBase.h"

// Sets default values for this component's properties
UWeaponComponent::UWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Initialize fire rate
	FireRate = 0.25f;
	bIsFiringWeapon = false;
}


// Called when the game starts
void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponComponent::StartFire()
{
	if (!bIsFiringWeapon)
	{
		bIsFiringWeapon = true;
		UWorld* World = GetWorld();
		World->GetTimerManager().SetTimer(FiringTimer, this, &UWeaponComponent::StopFire, FireRate, false);
		HandleFire();
	}
}

void UWeaponComponent::StopFire()
{
	bIsFiringWeapon = false;
}

void UWeaponComponent::HandleFire_Implementation()
{
	//FVector spawnLocation = GetActorLocation() + (GetActorRotation().Vector() * 100.0f) + (GetActorUpVector() * 50.0f);
	//FRotator spawnRotation = GetActorRotation();

	//FActorSpawnParameters spawnParameters;
	//spawnParameters.Instigator = GetInstigator();
	//spawnParameters.Owner = this;

	//AThirdPersonMPProjectile* spawnedProjectile = GetWorld()->SpawnActor<AThirdPersonMPProjectile>(spawnLocation, spawnRotation, spawnParameters);
}

