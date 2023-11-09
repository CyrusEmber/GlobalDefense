// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPawn.h"
#include "GameFramework/Pawn.h"
#include "EnemyBase.generated.h"

UCLASS()
class GLOBALDEFENSE_API AEnemyBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyBase();

	// Common properties
	UPROPERTY(EditAnywhere, Category = "Turret Properties")
	float Health = 100;

	UPROPERTY(EditAnywhere, Category = "Turret Properties")
	float EnemyDamage;

	UPROPERTY(EditAnywhere, Category = "Turret Properties")
	float Speed = 50;

	// Static Mesh 
	UPROPERTY(EditAnywhere, Category = StaticMesh)
	UStaticMeshComponent* TurretMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// Enemy function called globally
public:
	virtual void Initialization();
	//virtual void TakeDamage(float Damage);
	virtual void SimpleTakeDamage(float DamageAmount);
	// ENGINE_API virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

// Functions common to all Enemies
protected:
	virtual void Move();
	// Currently find a random turret target
	virtual void FindTarget();
	virtual void GetMovingDirection();
	FVector Direction;
	ATurretPawn* Target;
};
