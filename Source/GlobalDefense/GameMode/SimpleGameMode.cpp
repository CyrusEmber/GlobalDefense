// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleGameMode.h"
#include "Blueprint/UserWidget.h"
#include "../PlayerPawn.h"


void ASimpleGameMode::BeginPlay()
{
    Super::BeginPlay();
    ChangeMenuWidget(StartingWidgetClass);
    DefaultPawnClass = APlayerPawn::StaticClass();
}

void ASimpleGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget != nullptr)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass != nullptr)
    {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
        if (CurrentWidget != nullptr)
        {
            CurrentWidget->AddToViewport();
        }
    }
}

void ASimpleGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);
    FVector SpawnLocation = FVector(180, 520, 40);
    FRotator SpawnRotation = FRotator(0, 0, 0);
    // If you want to spawn a new pawn for each player
    if (NewPlayer)
    {
        APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, SpawnLocation, SpawnRotation);
        NewPlayer->Possess(NewPawn);
    }
}

//void ASimpleGameMode::Logout(AController* Exiting)
//{
//    // Cast the controller to APlayerController if needed
//    APlayerController* PC = Cast<APlayerController>(Exiting);
//
//    // Check if the controller is valid and has a pawn
//    if (PC && PC->GetPawn())
//    {
//        // Destroy the pawn associated with the player
//        PC->GetPawn()->Destroy();
//    }
//
//    // Call the base class Logout function
//    Super::Logout(Exiting);
//}