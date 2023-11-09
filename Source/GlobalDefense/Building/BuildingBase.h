// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingBase.generated.h"

/**
 * ABuildingBase is the parent class for all building types in the game.
 * It defines common properties, functionality, and interfaces that all buildings share.
 * This includes things like health, cost, and basic interactions such as damage and repair.
 * Subclasses are expected to extend this with specific behavior and additional properties as needed.
 */
UCLASS()
class GLOBALDEFENSE_API ABuildingBase : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingBase();
	/** Property replication */
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	/** Getter for Max Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetMaxHealth() const { return MaxHealth; }

	/** Getter for Current Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetCurrentHealth() const { return CurrentHealth; }

	/** Setter for Current Health. Clamps the value between 0 and MaxHealth and calls OnHealthUpdate. Should only be called on the server.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float healthValue);

	/** Event for taking damage. Overridden from APawn.*/
	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Static Mesh 
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* BuildingMesh;

	// Properties
	UPROPERTY(VisibleAnywhere, Category = "Building Properties")
	float BaseMaxHealth;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth)
	float MaxHealth;

	/** The player's current health. When reduced to 0, they are considered dead.*/
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Building Properties")
	int BaseCost;

	UPROPERTY(ReplicatedUsing = OnRep_Cost)
	int Cost;

	/** RepNotify functions*/
	UFUNCTION()
	void OnRep_MaxHealth();

	UFUNCTION()
	void OnRep_CurrentHealth();

	UFUNCTION()
	void OnRep_Cost();

protected:
	/** Response to health being updated. Called on the server immediately after modification, and on clients in response to a RepNotify*/
	void OnHealthUpdate();

protected:
	// Only handle destruction at server
	void HandleDestruction();



};
