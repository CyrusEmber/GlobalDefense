// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GLOBALDEFENSE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
    // Function to begin firing the weapon
    UFUNCTION(BlueprintCallable, Category = "Gameplay")
    void StartFire();

    // Function to stop firing the weapon
    UFUNCTION(BlueprintCallable, Category = "Gameplay")
    void StopFire();

protected:
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay|Projectile")
    TSubclassOf<class ABulletBase> BulletClass;

    // Timer handle for the firing rate delay
    FTimerHandle FiringTimer;

    // The rate of fire for the weapon
    UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
    float FireRate;

    // Whether or not the weapon is currently firing
    bool bIsFiringWeapon;

    // Server function to handle the actual firing logic
    // Because HandleFire is a Server RPC, its implementation in the CPP file must have the suffix _Implementation added to the function name.
    // Because it has the Server specifier, any attempt to call it on a client will result in the call being directed over the network to the authoritative Character on the server instead.
    UFUNCTION(Server, Reliable)
    void HandleFire();
};


