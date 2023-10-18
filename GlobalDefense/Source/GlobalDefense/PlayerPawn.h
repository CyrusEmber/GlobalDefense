// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class USphereComponent;
class ATurretPawn;
struct FInputActionValue;

UCLASS()
class GLOBALDEFENSE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();


private:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* BasicInputMapping;

	/** Actions */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* SpinAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* ZoomAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* RightClickAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* BuildAction;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AActor> SpotClass;

	/** Cursor Mesh */
	UPROPERTY(EditAnywhere, Category = StaticMesh)
	UStaticMeshComponent* Cursor;

	// Collision for the current mouse position
	UPROPERTY(VisibleAnywhere)
	USphereComponent* CursorHitBox;

	// Turret for spawning
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<ATurretPawn> TurretBase;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Inputs, need refactor to a controller
	void Move(const FInputActionValue& Value);
	void MoveActor(FVector2D& Movement);
	void Spin(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
	void Build(const FInputActionValue& Value);
	void RightClickSelectedActor(const FInputActionValue& Value);

/** Mutable Game Settings like camera moving speed */
private:
	float MovementSpeed;
	float RotationSpeed;
	float ZoomSpeed;
	float DefaultCursorRadius;

/** Immutable Game Settings */
private:
	// Define a range for zooming (adjust as needed)
	float MinZoomDistance = 500.0f;
	float MaxZoomDistance = 2000.0f;
	// Define the zoom interplation speed, which is updated in every frame
	float ZoomInterpSpeed;
	float DistanceTolarance = 1e-5;

/** Frame updates variables and functions */
private:
	// Zoom updates
	void UpdateZoom(float DeltaTime);
	int8 ZoomFrames = 0;
	bool bZooming = false; // A flag to indicate if zooming is in progress
	int8 MaxZoomFrames = 10;
	float ZoomTolerance = 0.1;
	float ZoomTargetArmLength;

	// Move edge scrolling updates
	void MouseEdgeScrolling();
	bool bEdgeScrolling = false;

	// Cursor hit result
	void UpdateCursorLocationByHItResult();
	FVector CachedCursorDestination;
	FVector CursorOffset = FVector(0.0f, 0.0f, 1.0f);

	// Cursor overlapping actors and moving the cursor to nearest actor with timer
	// Moniter the actor change by SelectedActor??
	void UpdateSelectedActor();
	TArray<AActor*> OverlappingActors;
	bool bIsCursorSelecting;
	FTimerHandle CursorMoveTimeCurrentPositionrHandle;
	FVector CurrentCursorLocation;
	FVector TargetCursorLocation;
	AActor* SelectedActor;
	ATurretPawn* CachedTurret = nullptr;
	const float Alpha = 0.1;

private:
	// Build mode
	bool bIsBuilding = false;


// Helper functions
private:
	FVector GetPositionOnGround(const UStaticMeshComponent* Mesh);
	float GetTargetCursorSize(const UStaticMeshComponent* Mesh);
	void DrawSelectedActorBindingBox(const UStaticMeshComponent* Mesh);
	void MoveCursorGradually(const FVector Destination);
	void SetCursorRadiusGradually(const float NewCursorRadius);

/** Debug */
private:
	AActor* PreviousSpot;
	FVector SpawnBall();

};
