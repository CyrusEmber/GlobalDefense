// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InformationUIWidget.generated.h"

/**
 * 
 */
struct TurretInfo;
UCLASS()
class GLOBALDEFENSE_API UInformationUIWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Type;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Damage;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Range;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* Cost;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* FireRate;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* HealthBar;

public:
	void UpdateDisplayInformation(TurretInfo& Info);

private:
	void SetTextBlock(UTextBlock* Block, float Value);
};
