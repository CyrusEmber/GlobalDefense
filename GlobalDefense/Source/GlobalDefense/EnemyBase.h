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
	float Health;

	UPROPERTY(EditAnywhere, Category = "Turret Properties")
	float Damage;

	UPROPERTY(EditAnywhere, Category = "Turret Properties")
	float Speed = 50;

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

	// Functions common to all turrets
public:
	virtual void Initialization();

protected:
	virtual void Move();
	// Currently find a random turret target
	virtual void FindTarget();
	virtual void GetMovingDirection();
	FVector Direction;
	ATurretPawn* Target;

};
