// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UEnhancedInputLocalPlayerSubsystem;
class ATurretPawn;
class UInformationUIWidget;
struct FInputActionValue;

UCLASS()
class GLOBALDEFENSE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "UI")
	const TSubclassOf<UUserWidget> HUDWidgetClass;

	UUserWidget* HUDWidgetInstance;

	UPROPERTY(EditAnywhere, Category = "UI")
	const TSubclassOf<UUserWidget> PauseWidgetClass;

	UUserWidget* PauseWidgetInstance;

	UPROPERTY(EditAnywhere, Category = "UI")
	const TSubclassOf<UUserWidget> InformationWidgetClass;

	UUserWidget* InformationWidgetInstance;

public:
	virtual void BeginPlay() override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	// Player's health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float CurrentHealth = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth = 100.0f;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthRatio() const;

// Initialization
private:
	void Initialization();
	void InitializeUI(TSubclassOf<UUserWidget> WidgetClass, UUserWidget* &WidgetInstance);


// Input
private:
	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* BasicInputMapping;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* UIInputMapping;

	UEnhancedInputLocalPlayerSubsystem* InputSystem;

	/** Actions */
	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* MoveAction;
	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* SpinAction;
	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* ZoomAction;
	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* BuildAction;
	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* PauseAction;
	//UPROPERTY(EditAnywhere, Category = Input)
	//UInputAction* RightClickAction;

	/** Input Functions */
	// Check if user assign all the variable in the BP
	void CheckActionInput();
	//void Move(const FInputActionValue& Value);
	//void Spin(const FInputActionValue& Value);
	//void Zoom(const FInputActionValue& Value);
	//void Build(const FInputActionValue& Value);
	void PauseMenu(const FInputActionValue& Value);
	//void RightClickSelectedActor(const FInputActionValue& Value);

	// Bool
	bool bGamePaused = false;

public:
	void UpdateInformationUI(ATurretPawn* TurretPawn);
	void ShowInformationUI();
	void HideInformationUI();
};
