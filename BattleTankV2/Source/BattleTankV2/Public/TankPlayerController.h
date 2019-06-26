// CopyRight Maximum LTD.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last item loaded

// Forward declarations
class UTankAimingComponent;

/**
 *  Responsible for helping the player aim.  
 */
UCLASS()
class BATTLETANKV2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimComRef);

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

	// Start the tank barrle moveing so that it can shoot at the crosshair
	void AimTowardsCrossHair();

private:

	//Fuctions
	bool GetSightRayHitLocation(FVector& HitLoaction) const;

	bool GetLookDiration(FVector2D ScreenLocation, FVector& LookDiraction) const;

	bool GetLookVectorHitLocation(FVector LookDiraction, FVector& HitLocation) const;
};
