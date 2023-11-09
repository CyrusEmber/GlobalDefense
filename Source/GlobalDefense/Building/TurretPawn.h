// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretPawn.generated.h"

class USphereComponent;
class AEnemyBase;
class ABulletBase;
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
    UPROPERTY(EditAnywhere, Category = TurretMesh)
    UStaticMeshComponent* TurretMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Bullet")
    TSubclassOf<ABulletBase> BulletClass;

private:
    // Common properties
    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    FString Type = "Base";

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float MaxHealth = 15;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float CurrentHealth = 10;

    UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
    float TurretDamage = 1;

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
    void TriggerEnter(class UPrimitiveComponent* HitComp, class AActor* OtherActor, 
        class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* HitComp, class AActor* OtherActor, 
        class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    // List of actors in range
    TArray<AEnemyBase*> EnemiesInRange;
    TArray<APawn*> AlliesInRange;

protected:
    // Functions to be implemented in derived classes
    virtual void RotateTurretTowardsTarget();

// Functions common to all turrets
public:
    // Spawn the turrent above ground
    virtual void Initialization();
    virtual void ShowRange();
    virtual void ShowDebug();
    float ActorLocationZ;

// Setup overlay 
public:
    void SetRedOverlay();
    void SetGreenOverlay();
    void ResetOverlay();

    // Function to update the placement overlay's position
    void UpdatePlacementOverlay(const FVector& NewLocation);

private:
    //// The visual component used as an overlay, could be a separate mesh, decal, etc.
    //UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Overlay", meta = (AllowPrivateAccess = "true"))
    //UStaticMeshComponent* PlacementOverlayMesh;

    //// Indicates whether the placement overlay is currently enabled
    //bool bPlacementOverlayEnabled;

    // Overlay Materials consider rename?
    UPROPERTY(EditAnywhere, Category = "Material")
    UMaterialInterface* GreenOverlayMaterial;

    UPROPERTY(EditAnywhere, Category = "Material")
    UMaterialInterface* RedOverlayMaterial;

    

private:
    virtual FVector FindTargetEnemyLocation();
    virtual bool IsEnemyInRange();
    virtual void Fire();
    virtual ABulletBase* SpawnBullet(const FVector& SpawnLocation, const FVector& LaunchDirection);
    virtual void StartFiring();
    virtual void StopFiring();

    virtual void UpgradeInGame();
    virtual void UpgradeBySkillTree();
    // Timer handle for controlling the rate of fire
    FTimerHandle FiringTimer;




};


