// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last item loaded

/**
 * 
 */
UCLASS()
class BATTLETANKV2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Start the tank barrle moveing so that it can shoot at the crosshair
	void AimTowardsCrossHair();

private:

	bool GetSightRayHitLocation(FVector& OutHitLoaction) const;
};
