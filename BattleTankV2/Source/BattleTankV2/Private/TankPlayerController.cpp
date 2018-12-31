// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTrank = GetControlledTank();
	if (!ControlledTrank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController cant Find Controlled Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing %s"), *(ControlledTrank->GetName()));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter 
	if (GetSightRayHitLocation(HitLocation)) // Has "Side-effect" id going to Raytrace 
	{
		UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString());
		// TODO Tell Controlled Tank to aim at this point
	}
}

// Get world location of Raytrace through Crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLoaction) const
{
	OutHitLoaction = FVector(1.0);
	return true;
}

