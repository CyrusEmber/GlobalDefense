// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "TopDownCameraActor.generated.h"

/**
 * 
 */

UCLASS()
class GLOBALDEFENSE_API ATopDownCameraActor : public ACameraActor
{
	GENERATED_BODY()
	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

public:
	// Sets default values for this actor's properties
	ATopDownCameraActor();

protected:
    // Declare camera components here

	
};
