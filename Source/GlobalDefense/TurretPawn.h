// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretPawn.generated.h"

class USphereComponent;
struct TurretInfo
{
    FString Type = "";
    float Damage = 0;
    float Range = 0;
    float FireRate = 0;
    int Cost = 0;
    float HealthRatio = 0;
};
UCLASS()
class GLOBALDEFENSE_API ATurretPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurretPawn();

    // Static Mesh 
    UPROPERTY(EditAnywhere, Category = StaticMesh)
    UStaticMeshComponent* StaticMeshComponent;

private:
    // Common properties
    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    FString Type = "Base";

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float MaxHealth = 15;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float CurrentHealth = 10;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float Damage = 1;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float Range = 5 * 100.f;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float FireRate = 1;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    int Cost = 1;

public:
    TurretInfo GetTurretInfo();
    FString GetType();
    float GetDamage();
    float GetRange();
    float GetFireRate();
    float GetHealthRatio();
    int GetCost();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Trigger Volume
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trigger Volume")
    USphereComponent* TriggerVolume;
    UFUNCTION()
    void TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    // List of actors in range
    TArray<APawn*> EnemiesInRange;
    TArray<APawn*> AlliesInRange;

protected:
    // Functions to be implemented in derived classes
    virtual void RotateTurretTowardsTarget();

// Functions common to all turrets
public:
    virtual void Initialization();
    virtual void ShowRange();
    virtual void ShowDebug();
private:
    virtual void FindTargetEnemy();
    virtual void Fire();
    virtual void UpgradeInGame();
    virtual void UpgradeBySkillTree();




};


