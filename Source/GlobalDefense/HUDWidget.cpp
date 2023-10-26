// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDWidget.h"
#include "Components/ProgressBar.h"
#include "MyPlayerController.h"

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
    UpdateHealth();
}

void UHUDWidget::UpdateHealth()
{
    AMyPlayerController* PC = Cast<AMyPlayerController>(GetOwningPlayer());
    // Assuming HealthBar is the ProgressBar widget
    if (PC && HealthBar)
    {
        HealthBar->SetPercent(PC->GetHealthRatio());
    }
    

}
