// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PlayerPawn.h"
#include "TurretPawn.h"
#include "InformationUIWidget.h"


void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());

    // Set up input
    if (InputComponent) {
        SetupPlayerInputComponent(InputComponent);
    }
    // Set up input mapping
    InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer());
    if (InputSystem) {
        InputSystem->AddMappingContext(BasicInputMapping, 0);
    }
    else {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Controller cannot find input subsystem!")));
    }

    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn) {
        APlayerPawn* CurrentPawn = Cast<APlayerPawn>(ControlledPawn);
        if (CurrentPawn) {
            //CurrentPawn->MyFunction();
        }
    }
    //if (HUDWidgetClass) {
    //    // Create the pause menu only if it hasn't been created yet
    //    HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);

    //    if (HUDWidgetInstance) {
    //        HUDWidgetInstance->AddToViewport();
    //    }
    //}
    CheckActionInput();
    Initialization();
}



void AMyPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
        // Pause
        EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AMyPlayerController::PauseMenu);
    }
    else {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("No enhanced input for my player controller")));
    }
}

float AMyPlayerController::GetHealthRatio() const
{
    return CurrentHealth / MaxHealth;
}

void AMyPlayerController::Initialization()
{
    // UI
    InitializeUI(HUDWidgetClass, HUDWidgetInstance);
    InitializeUI(PauseWidgetClass, PauseWidgetInstance);
    //InitializeUI(InformationWidgetClass, InformationWidgetInstance);
    if (PauseWidgetInstance) {
        PauseWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
    }
    if (InformationWidgetInstance) {
        InformationWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
    }
    //PauseWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
    //InformationWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
}

void AMyPlayerController::InitializeUI(TSubclassOf<UUserWidget> WidgetClass, UUserWidget* &WidgetInstance)
{
    if (WidgetClass) {
        // Create the pause menu only if it hasn't been created yet
        WidgetInstance = CreateWidget<UUserWidget>(this, WidgetClass);

        if (WidgetInstance) {
            WidgetInstance->AddToViewport();
        }
    }
    else {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("No WidgetClass in BP")));
    }
}

void AMyPlayerController::CheckActionInput()
{
    if (!PauseAction) {
        GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, FString::Printf(TEXT("Invalid input in my player controller BP")));
    }
}

void AMyPlayerController::PauseMenu(const FInputActionValue& Value)
{
    bGamePaused = !bGamePaused;
    //GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow,
    //    FString::Printf(TEXT("Pause in my Player Controller: %s"), bGamePaused ? TEXT("true") : TEXT("false")));


    if (bGamePaused) {
        //SetPause(true);
       if (PauseWidgetInstance) {
            PauseWidgetInstance->SetVisibility(ESlateVisibility::Visible);
        }
        //InputSystem->AddMappingContext(UIInputMapping, 1);
    }
    else {
        //SetPause(false);
        // Hide the pause menu
        if (PauseWidgetInstance) {
            PauseWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
        } 
        //InputSystem->RemoveMappingContext(UIInputMapping);
    }
}

void AMyPlayerController::UpdateInformationUI(ATurretPawn* TurretPawn)
{
    UInformationUIWidget* InformationUI = dynamic_cast<UInformationUIWidget*>(InformationWidgetInstance);
    TurretInfo Info = TurretPawn->GetTurretInfo();
    if (InformationUI) {
        InformationUI->UpdateDisplayInformation(Info);
    }
}

void AMyPlayerController::ShowInformationUI()
{
    InformationWidgetInstance->SetVisibility(ESlateVisibility::Visible);
}

void AMyPlayerController::HideInformationUI()
{
    InformationWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
}
