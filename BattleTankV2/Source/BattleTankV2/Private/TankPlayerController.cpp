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
		//UE_LOG(LogTemp, Warning, TEXT("Hitlocation: %s"), *HitLocation.ToString());
		// TODO Tell Controlled Tank to aim at this point
	}
}

// Get world location of Raytrace through Crosshair, true if hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLoaction) const
{
	// Find the crosshair position in pixal cordaintes 
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLoaction, ViewportSizeY * CrossHairYLoaction);

	// "De-Project" the screen position pof the crosshair to a world direction
	FVector LookDiraction;
	if (GetLookDiration(ScreenLocation, LookDiraction))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Diraction: %s"), *LookDiraction.ToString());
	}

	// RayTrace along that look direction, and see whats is hit (limted range)
	return true;
}

bool ATankPlayerController::GetLookDiration(FVector2D ScreenLocation, FVector& LookDiraction) const
{
	FVector CameraWorldLocation; // To be disguarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDiraction
	);
}

