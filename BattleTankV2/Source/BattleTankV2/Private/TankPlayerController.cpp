// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	AimTowardsCrossHair();
	Super::Tick(DeltaTime);
	
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

	// Get world location through Crosshair 
	// If it hits Landscape
		// Tell Controlled Tank to aim at this point
}

