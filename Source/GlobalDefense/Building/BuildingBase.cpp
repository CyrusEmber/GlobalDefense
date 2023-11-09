// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingBase.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

// Sets default values
ABuildingBase::ABuildingBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    bReplicates = true;
    SetReplicatingMovement(true);

}

void ABuildingBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicate current health.
	DOREPLIFETIME(ABuildingBase, CurrentHealth);
	DOREPLIFETIME(ABuildingBase, Cost);
}

void ABuildingBase::SetCurrentHealth(float healthValue)
{
    if (GetLocalRole() == ROLE_Authority)
    {
        CurrentHealth = FMath::Clamp(healthValue, 0.f, MaxHealth);
        OnHealthUpdate();
    }
}

float ABuildingBase::TakeDamage(float DamageTaken, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
    float damageApplied = CurrentHealth - DamageTaken;
    SetCurrentHealth(damageApplied);
    return damageApplied;
}

// Called when the game starts or when spawned
void ABuildingBase::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ABuildingBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuildingBase::OnRep_CurrentHealth()
{
    OnHealthUpdate();
}

void ABuildingBase::OnRep_MaxHealth()
{
}

void ABuildingBase::OnRep_Cost()
{
}

void ABuildingBase::OnHealthUpdate()
{
    //Client-specific functionality
    if (IsLocallyControlled())
    {
        if (CurrentHealth <= 0)
        {
            FString deathMessage = FString::Printf(TEXT("Been killed."));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, deathMessage);
        }
    }

    //Server-specific functionality
    if (GetLocalRole() == ROLE_Authority)
    {
        FString healthMessage = FString::Printf(TEXT("%s now has %f health remaining."), *GetFName().ToString(), CurrentHealth);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, healthMessage);
        if (CurrentHealth <= 0)
        {
            HandleDestruction();
        }
    }

    //Functions that occur on all machines.
    /*
        Any special functionality that should occur as a result of damage or death should be placed here.
    */

}

void ABuildingBase::HandleDestruction()
{
    Destroy();
}

