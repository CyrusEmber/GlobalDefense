// Fill out your copyright notice in the Description page of Project Settings.


#include "InformationUIWidget.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"
#include "TurretPawn.h"

void UInformationUIWidget::UpdateDisplayInformation(TurretInfo& Info)
{
	Type->SetText(FText::FromString(Info.Type));
	Damage->SetText(FText::AsNumber(Info.Damage));
	Range->SetText(FText::AsNumber(Info.Range));
	FireRate->SetText(FText::AsNumber(Info.FireRate));
	Cost->SetText(FText::AsNumber(Info.Cost));
	HealthBar->SetPercent(Info.HealthRatio);
}
