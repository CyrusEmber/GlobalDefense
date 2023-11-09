// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationUIWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "../Building/TurretPawn.h"

void UInformationUIWidget::UpdateDisplayInformation(TurretInfo& Info)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, "Type" + Info.Type);
	Type->SetText(FText::FromString("Type: " + Info.Type));
	FString DamageString = "Damage: " + FString::SanitizeFloat(Info.Damage);
	Damage->SetText(FText::FromString(DamageString));
	FString RangeString = "Range: " + FString::SanitizeFloat(Info.Range);
	Range->SetText(FText::FromString(RangeString));

	FireRate->SetText(FText::AsNumber(Info.FireRate));
	Cost->SetText(FText::AsNumber(Info.Cost));
	HealthBar->SetPercent(Info.HealthRatio);
}

void UInformationUIWidget::SetTextBlock(UTextBlock* Block, float Value)
{
}
