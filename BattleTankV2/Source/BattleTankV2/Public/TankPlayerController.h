// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last item loaded

// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANKV2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	//Varables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interface")
	float CrossHairXLoaction = 0.5;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interface")
	float CrossHairYLoaction = 0.333;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "RayTracing")
	float LineTraceRange = 1000000;

	//Fuctions
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Start the tank barrle moveing so that it can shoot at the crosshair
	void AimTowardsCrossHair();

private:

	//Fuctions
	bool GetSightRayHitLocation(FVector& HitLoaction) const;

	bool GetLookDiration(FVector2D ScreenLocation, FVector& LookDiraction) const;

	bool GetLookVectorHitLocation(FVector LookDiraction, FVector& HitLocation) const;
};
