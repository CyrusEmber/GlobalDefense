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

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

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

public:
	// Inputs, need refactor to a controller
	void Move(const FInputActionValue& Value);
	void MoveCamera(FVector2D& Movement);
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
	void MouseEdgeScrolling(FVector2D CursorScreenPosition);
	bool bEdgeScrolling = false;

	// Spin
	FVector CameraCenterLocation;

	// Cursor hit result
	void CursorMove();
	void UpdateCursorLocationByHItResult(FVector2D CursorScreenPosition);
	AActor* GetClosestActorToCursor(const TArray<AActor*>& Actors);
	FVector CachedCursorDestination;
	FVector CursorOffset = FVector(0.0f, 0.0f, 1.0f);

	// Cursor overlapping actors and moving the cursor to nearest actor with timer
	// Moniter the actor change by SelectedActor??
	void UpdateSelectedActor();
	TArray<AActor*> OverlappingActors;
	bool bIsCursorSelecting;
	FTimerHandle CursorMoveTimeCurrentPositionHandle;
	FVector CurrentCursorLocation;
	FVector TargetCursorLocation;
	AActor* SelectedActor;
	
	const float Alpha = 0.1;

// Build mode
private:
	bool bIsBuilding = false;
	bool bIsActorColliding = false;
	ATurretPawn* TurretPreview = nullptr;
	TArray<AActor*> PreviewOverlappingActors;

	void UpdateTurretPreview();
	// Destroy certain components make it only a mesh
	void CreateTurretPreview();

private:
	FVector GridSnapping(FVector CurrentLocation);
	// Place the actor on ground according to grid snapping
	AActor* PlaceActorGridSnapping();
	// Need lerp? Only move in 2D
	void MoveActorGridSnapping2D(AActor* Actor);
	// Cached grid snapping location for build mode, used to check if the current location snapping location is same as this, otherwise move the actor. Set it to nullptr when build mode ends
	FVector CachedRoundedDestination;


// Helper functions
private:
	FVector GetPositionOnBottom(const UStaticMeshComponent* Mesh);
	float GetTargetCursorSize(const UStaticMeshComponent* Mesh);
	void DrawSelectedActorBindingBox(const UStaticMeshComponent* Mesh);
	void MoveCursorGradually(const FVector Destination);
	void SetCursorRadiusGradually(const float NewCursorRadius);
	// Update the actor information and show the UI when the actor is some turret.
	void OnSelectedActorChanged(AActor* ChangedActor);



/** Debug */
private:
	AActor* PreviousSpot;
	FVector SpawnBall();
	void DebugLog(FString BugString);

};
