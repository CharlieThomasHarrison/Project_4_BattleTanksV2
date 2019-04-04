// CopyRight Maximum LTD.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

// Enum For aiming state
UENUM()
enum class EFireingState : uint8
{
	Reloading,
	Amining, 
	Locked
};

// Forward Declaration
class UTankBarrel;
class UTankTurret;

// Hold barrel's properties and Elvate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKV2_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFireingState FireingState = EFireingState::Amining;

private:
	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;


};
