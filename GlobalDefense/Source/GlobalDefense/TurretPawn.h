// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretPawn.generated.h"

class USphereComponent;
UCLASS()
class GLOBALDEFENSE_API ATurretPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurretPawn();

    // Common properties
    UPROPERTY(EditAnywhere, Category = "Turret Properties")
    float Damage;

    UPROPERTY(EditAnywhere, Category = "Turret Properties")
    float Range = 100.f;

    UPROPERTY(EditAnywhere, Category = "Turret Properties")
    float FireRate;

    // Static Mesh 
    UPROPERTY(EditAnywhere, Category = StaticMesh)
    UStaticMeshComponent* StaticMeshComponent;


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

    
private:
    // Functions common to all turrets
    virtual void FindTargetEnemy();
    virtual void Fire();
    virtual void UpgradeInGame();
    virtual void UpgradeBySkillTree();



};


