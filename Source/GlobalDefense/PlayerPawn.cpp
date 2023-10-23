// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "TurretPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	if (!RootComponent) {
		RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	}

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Create StaticMesh component
	Cursor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cursor"));
	Cursor->SetupAttachment(RootComponent);
	// Disable overlap events for cursor to disable get actor result
	Cursor->SetGenerateOverlapEvents(false);

	// Create Sphere Component for collision detection
	CursorHitBox = CreateDefaultSubobject<USphereComponent>(TEXT("CursorHitBox"));
	CursorHitBox->SetupAttachment(RootComponent);
	CursorHitBox->SetSphereRadius(64.f);
	CursorHitBox->CanCharacterStepUpOn = ECB_No;

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Setup Player Controller not working
	//APlayerController* PlayerController = Cast<APlayerController>(Controller);
	//if (PlayerController) {
	//	PlayerController->bShowMouseCursor = true;
	//}

	// Setup camera settings
	MovementSpeed = 1000.0f;
	RotationSpeed = 100.0f;
	ZoomSpeed = 100.0f;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->AddMappingContext(BasicInputMapping, 0);
		}
	}
	// Initialize Actor location (on the ground)
	FVector CamCenterLocation = SpawnBall();
	SetActorLocation(CamCenterLocation);
	CamCenterLocation.Z += 5.0f;
	// Initialize Cursor and Hitbox location
	CachedCursorDestination = CamCenterLocation;
	Cursor->SetWorldLocation(CachedCursorDestination);
	Cursor->SetWorldRotation(FRotator::ZeroRotator);
	CursorHitBox->SetWorldLocation(CachedCursorDestination);

	// Get the original radius of cursor 50*50
	FBox CursorBox = Cursor->Bounds.GetBox();
	FVector CursorExtents = CursorBox.GetExtent();
	DefaultCursorRadius = CursorExtents.X;

	//FString DebugString = CursorExtents.ToString();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Forward: %s"), *DebugString));

}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateZoom(DeltaTime);
	MouseEdgeScrolling();
	UpdateCursorLocationByHItResult();
	UpdateSelectedActor();
	// Debug ball
	SpawnBall();
}



// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
		// Spinning
		EnhancedInputComponent->BindAction(SpinAction, ETriggerEvent::Triggered, this, &APlayerPawn::Spin);
		// Zooming
		EnhancedInputComponent->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &APlayerPawn::Zoom);
		// Right Clicking
		EnhancedInputComponent->BindAction(RightClickAction, ETriggerEvent::Started, this, &APlayerPawn::RightClickSelectedActor);
		// Build
		EnhancedInputComponent->BindAction(BuildAction, ETriggerEvent::Started, this, &APlayerPawn::Build);
	}
}

// Move according to the looking direction
void APlayerPawn::Move(const FInputActionValue& Value)
{
	// Players are allowed one moving strategy at a time
	if (bEdgeScrolling) {
		return;
	}
	
	// Input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	MoveActor(MovementVector);
}

// Move according to the looking direction
void APlayerPawn::MoveActor(FVector2D& MovementVector)
{
	FVector Movement(MovementVector.Y, MovementVector.X, 0.0f);
	// find out which way is forward
	const FRotator Rotation = GetActorRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	Movement = YawRotation.RotateVector(Movement);

	// Adjust the actor's position to move the camera
	FVector MovementChange = Movement * MovementSpeed * GetWorld()->GetDeltaSeconds();
	FVector NewLocation = GetActorLocation() + MovementChange;
	SetActorLocation(NewLocation);
}

// Spin around the camera center
void APlayerPawn::Spin(const FInputActionValue& Value)
{
	float AngleDelta = Value.Get<float>();
	AngleDelta = FMath::Clamp(AngleDelta, -1, 1);
	float RotationChange = AngleDelta * RotationSpeed * GetWorld()->GetDeltaSeconds();

	// Adjust the rotation of the character
	FRotator NewRotation = GetActorRotation() + FRotator(0.0f, RotationChange, 0.0f);
	SetActorRotation(NewRotation);
}

// Zoom has a certain range defined by MinZoomDistance and MaxZoomDistance of ArmLength.
void APlayerPawn::Zoom(const FInputActionValue& Value)
{
	float ZoomDelta = Value.Get<float>();
	ZoomDelta = FMath::Clamp(ZoomDelta, -1, 1);

	// Update the CameraBoom's TargetArmLength
	ZoomTargetArmLength = CameraBoom->TargetArmLength + ZoomDelta * ZoomSpeed;

	// Check if the distance is within the specified range
	if (ZoomTargetArmLength < MinZoomDistance || ZoomTargetArmLength > MaxZoomDistance) {
	return;
	}
	ZoomTargetArmLength = FMath::Clamp(ZoomTargetArmLength, MinZoomDistance, MaxZoomDistance);

	// Start Zooming
	bZooming = true;
	ZoomFrames = 0;
}

// Need UI interactions
void APlayerPawn::Build(const FInputActionValue& Value)
{
	bIsBuilding = !bIsBuilding;
	// Check if we are in build mode, need to check this at tick
	if (bIsBuilding) {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("In Build Mode")));
	}
}

// Only when player right click when they are selecting an actor, we call this function
void APlayerPawn::RightClickSelectedActor(const FInputActionValue& Value)
{
	if (!bIsBuilding) {
		if (!bIsCursorSelecting) {
			return;
		}
		FString ActorName = SelectedActor->GetName();
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Right Click on selected Actor: %s"), *ActorName));
		ATurretPawn* Turret = dynamic_cast<ATurretPawn*>(SelectedActor);
		if (Turret)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Right Click on a turret")));
			Turret->ShowRange();
		}

		
	} 
	else {
		if (!bIsCursorSelecting) {
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Spawn Something")));
			FRotator Rotation = FRotator(0, 0, 0);
			float Scale = 0;
			FActorSpawnParameters SpawnParams;
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			FVector NewDestination = FVector(CachedCursorDestination.X, CachedCursorDestination.Y, CachedCursorDestination.Z + 0.f);

			ATurretPawn* NewTurret = GetWorld()->SpawnActor<ATurretPawn>(TurretBase, NewDestination, FRotator::ZeroRotator, SpawnParams);
			NewTurret->Initialization();
			//TurretBase->Spawn(CachedCursorDestination, Rotation, Scale);
		}
		else {
			FString ActorName = SelectedActor->GetName();
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Right Click on selected Actor: %s"), *ActorName));
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("You cannot place turret on another turret!")));
		}

	} 
}

void APlayerPawn::UpdateZoom(float DeltaTime)
{
	if (bZooming)
	{
		float CurrentTargetArmLength = CameraBoom->TargetArmLength;
		
		// Interpolate the TargetArmLength towards the target zoom level
		ZoomInterpSpeed = FMath::Abs(ZoomTargetArmLength - CurrentTargetArmLength) / MaxZoomFrames;
		CameraBoom->TargetArmLength = FMath::FInterpTo(CurrentTargetArmLength, ZoomTargetArmLength, DeltaTime, ZoomInterpSpeed);

		ZoomFrames++;
		// Check if we reached the desired zoom level or frame count
		if (FMath::IsNearlyEqual(CurrentTargetArmLength, ZoomTargetArmLength, ZoomTolerance))
		{
			bZooming = false;
		}
		// Or if we've reached the desired number of frames for zooming
		else if (ZoomFrames >= MaxZoomFrames)
		{
			bZooming = false;
		}
	}
}

/** Defined ScreenWidth ScreenHeight ScrollZoneSize*/
void APlayerPawn::MouseEdgeScrolling()
{
	const float ScreenWidth = GEngine->GameViewport->Viewport->GetSizeXY().X;
	const float ScreenHeight = GEngine->GameViewport->Viewport->GetSizeXY().Y;
	const float ScrollZoneSize = ScreenWidth * 0.08;
	float MouseX, MouseY; 

	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController && PlayerController->GetMousePosition(MouseX, MouseY))
	{
		// Display the FString using AddOnScreenDebugMessage
		float DistanceToTop = MouseY; 
		float DistanceToBottom = ScreenHeight - MouseY;
		float DistanceToLeft = MouseX;
		float DistanceToRight = ScreenWidth - MouseX;

		FVector2D MovementVector = FVector2D(0.f, 0.f);
		// Check if the cursor is within scroll zone
		if (DistanceToTop < ScrollZoneSize)
		{
			MovementVector.Y += 1 - DistanceToTop / ScrollZoneSize;
		}

		else if (DistanceToBottom < ScrollZoneSize)
		{
			MovementVector.Y -= 1 - DistanceToBottom / ScrollZoneSize;
		}

		if (DistanceToLeft < ScrollZoneSize)
		{
			MovementVector.X -= 1 - DistanceToLeft / ScrollZoneSize;
		}

		else if (DistanceToRight < ScrollZoneSize)
		{
			MovementVector.X += 1 - DistanceToRight / ScrollZoneSize;
		}

		if (MovementVector == FVector2D(0.0f, 0.0f)) {
			bEdgeScrolling = false;
			return;
		}
		else {
			bEdgeScrolling = true;
			MoveActor(MovementVector);
		}
	}
}

// Update cursor and cursor hitbox location according to the mouse position
void APlayerPawn::UpdateCursorLocationByHItResult()
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	// Ignore the player's pawn or cursor actor
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredComponent(Cursor);


	float MouseX, MouseY;
	if (PlayerController && PlayerController->GetMousePosition(MouseX, MouseY)) {
		PlayerController->GetMousePosition(MouseX, MouseY);
		FVector2D CursorScreenPosition = FVector2D(MouseX, MouseY);
		bHitSuccessful = PlayerController->GetHitResultAtScreenPosition(CursorScreenPosition, ECollisionChannel::ECC_Visibility, CollisionParams, Hit);
		//bHitSuccessful = PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_PhysicsBody, true, Hit);

		// If we hit a surface, cache the location
		if (bHitSuccessful)
		{
			CachedCursorDestination = Hit.Location;
		}
		
		CursorHitBox->SetWorldLocation(CachedCursorDestination);
		// Not allow cursor updating when selecting
		// Rescale
		if (!bIsCursorSelecting) {
			MoveCursorGradually(CachedCursorDestination);
			SetCursorRadiusGradually(0.5 * DefaultCursorRadius);
		}
	}
}

void APlayerPawn::UpdateSelectedActor()
{
	CursorHitBox->GetOverlappingActors(OverlappingActors);

	if (OverlappingActors.Num() == 0) {
		bIsCursorSelecting = false;
		return;
	}
	else {
		// Set a flag to indicate that selected some actor
		bIsCursorSelecting = true;
	}
		
	//// Debug
	//else {
	//	for (AActor* Actor : OverlappingActors) {
	//		FString LocationString = Actor->GetName();
	//		
	//		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("OverlappingActors numbers: %s"), *LocationString));
	//	}
	//	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("OverlappingActors numbers: %d"), OverlappingActors.Num()));
	//}
	
	// Find the closest actor
	SelectedActor = OverlappingActors[0];
	float MinDistance = 10000.f;
	for (AActor* Actor : OverlappingActors)
	{
		FVector ActorPosition = Actor->GetActorLocation();
		float Actor2CursorDistance = FVector::Dist(CachedCursorDestination, ActorPosition);
		if (Actor2CursorDistance < MinDistance) {
			MinDistance = Actor2CursorDistance;
			SelectedActor = Actor;
		}
	}
	// Move the cursor to the closest actor smoothly with Lerp transition
	if (SelectedActor)
	{
		//CachedTurret = dynamic_cast<ATurretPawn*>(SelectedActor);
		// Get the static mesh component of the closest seleted actor
		UStaticMeshComponent* StaticMeshComponent = SelectedActor->FindComponentByClass<UStaticMeshComponent>();
		if (!StaticMeshComponent)
		{
			FString ActorName = SelectedActor->GetName();
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("No StaticMeshComponent for Actor: %s"), *ActorName));
		}
		CurrentCursorLocation = Cursor->GetComponentLocation();
		TargetCursorLocation = GetPositionOnGround(StaticMeshComponent);
		DrawSelectedActorBindingBox(StaticMeshComponent);

		// Set cursor 
		MoveCursorGradually(TargetCursorLocation);
		float NewCursorRadius = GetTargetCursorSize(StaticMeshComponent);
		SetCursorRadiusGradually(NewCursorRadius);
	}
}
// For a actor center position, find its position on the ground by the component bounds 

// Suppose the actor center is binding box center
FVector APlayerPawn::GetPositionOnGround(const UStaticMeshComponent* Mesh)
{

	FVector MeshCenterPosition = Mesh->GetComponentLocation();
	FBox MeshBox = Mesh->Bounds.GetBox();

	FVector Extents = MeshBox.GetExtent(); // Gets half of the binding box

	float ZExtent = Extents.Z;
	MeshCenterPosition.Z -= ZExtent;
	return MeshCenterPosition;
}

float APlayerPawn::GetTargetCursorSize(const UStaticMeshComponent* Mesh)
{
	FBox MeshBox = Mesh->Bounds.GetBox();

	FVector Extents = MeshBox.GetExtent();
	return FMath::Max(Extents.X, Extents.Y);
}

// Unreal default generate AABB bindingBox, I want to draw the highlighted binding box by revert the rotation on Z axis for a Cube now
void APlayerPawn::DrawSelectedActorBindingBox(const UStaticMeshComponent* Mesh)
{

	FVector MeshCenterPosition = Mesh->GetComponentLocation();
	FBox MeshBox = Mesh->Bounds.GetBox();
	FVector Extents = MeshBox.GetExtent(); // Gets half of the +binding box

	// Binding box highlight
	FColor DebugColor = FColor::Red;
	float DebugDuration = 0.0f; // Time in seconds
	// Get actor rotation
	FRotator ActorRotation = Mesh->GetComponentRotation();

	// Turn the box into OOB style
	float DegreeOnZ = ActorRotation.Euler().Z;
	float Radians = FMath::DegreesToRadians(DegreeOnZ);
	float Coefficient = FMath::Abs(FMath::Sin(Radians)) + FMath::Abs(FMath::Cos(Radians));
	Extents.X = Extents.X / Coefficient;
	Extents.Y = Extents.Y / Coefficient;

	//// Get the center and extents of the local bounding box
	//FVector Center = ActorBox.GetCenter();
	//const auto Transform = Actor->GetTransform();
	//// Calculate the world space extents for an OBB
	//const FVector Forward = Transform.TransformVector(Extents.X * FVector::ForwardVector);
	//const FVector Right = Transform.TransformVector(Extents.Y * FVector::RightVector);
	//const FVector Up = Transform.TransformVector(Extents.Z * FVector::UpVector);

	//FString ForwardString = Forward.ToString();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Forward: %s"), *ForwardString));
	//ForwardString = Right.ToString();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Right: %s"), *ForwardString));
	//ForwardString = Up.ToString();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Up: %s"), *ForwardString));
	// https://forums.unrealengine.com/t/object-oriented-bounding-box-from-either-aactor-or-mesh/326571/6

	// Draw the debug box in the world
	DrawDebugBox(
		GetWorld(),
		MeshCenterPosition,
		Extents,
		ActorRotation.Quaternion(),
		DebugColor,
		false,
		DebugDuration,
		0,
		2
	);
	
}

// Change the location of cursor gradually
void APlayerPawn::MoveCursorGradually(const FVector Destination)
{
	FVector CurrentPosition = Cursor->GetComponentLocation();
	Cursor->SetWorldLocation(FMath::Lerp(CurrentPosition, Destination + CursorOffset, 0.1f));
}

// Rescale the default cursor radius at runtime. Scale the new cursor radius to fit the visual
void APlayerPawn::SetCursorRadiusGradually(const float NewCursorRadius)
{
	
	float Scale = 2 * NewCursorRadius / DefaultCursorRadius;
	//FString boolString = bIsCursorSelecting ? TEXT("True") : TEXT("False");

	FVector NewScale = FVector(Scale, Scale, Scale);
	Cursor->SetWorldScale3D(FMath::Lerp(Cursor->GetComponentScale(), NewScale, 0.1f));
}



FVector APlayerPawn::SpawnBall()
{
	// Get the camera's location and forward vector
	FVector CameraLocation = TopDownCameraComponent->GetComponentLocation();
	FVector CameraForward = TopDownCameraComponent->GetForwardVector();

	// Define the trace parameters
	FHitResult HitResult;
	FCollisionQueryParams TraceParams(FName(TEXT("CameraTrace")), false, this);
	TraceParams.AddIgnoredActor(PreviousSpot);

	// Perform the line trace
	FVector StartTrace = CameraLocation;
	float TraceDistance = 2000.0f;
	FVector EndTrace = StartTrace + CameraForward * TraceDistance; // Define TraceDistance as needed
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartTrace, EndTrace, ECC_Visibility, TraceParams);
	FVector HitLocation;

	if (bHit)
	{
		// Get the hit position vector
		HitLocation = HitResult.ImpactPoint;
		// Spawn a spot or marker at the hit location
		AActor* NewSpot = GetWorld()->SpawnActor<AActor>(SpotClass, HitLocation, FRotator::ZeroRotator);

		if (PreviousSpot)
		{
			PreviousSpot->Destroy();
		}

		PreviousSpot = NewSpot;
	}

	return HitLocation;

}

