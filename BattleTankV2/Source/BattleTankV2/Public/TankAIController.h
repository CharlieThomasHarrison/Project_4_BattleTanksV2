// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKV2_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close the AI Tank can get (In Centermeters)
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider editDefaultsonly
	float AcceptanceRadius = 3000;


private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

};
