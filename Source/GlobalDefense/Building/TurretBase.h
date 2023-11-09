// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "TurretBase.generated.h"

/**
 * 
 */
UCLASS()
class GLOBALDEFENSE_API ATurretBase : public ABuildingBase
{

	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ATurretBase();

// Common properties	
protected:
	UPROPERTY(VisibleAnywhere, Category = "Turret Properties")
	FString Type = "Base";
};
