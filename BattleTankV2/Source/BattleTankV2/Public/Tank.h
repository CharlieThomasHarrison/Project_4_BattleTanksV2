// CopyRight Maximum LTD.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new incules above

// Forward declarations
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTLETANKV2_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fireing")
	float LaunchSpeed = 10000;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fireing")
	bool CanTankFire = true;

protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = "Fireing")
	float ReloadTimeInSeconds = 3;

	// Local Barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; //TODO remove
	
	double LastFireTime = 0;

};
