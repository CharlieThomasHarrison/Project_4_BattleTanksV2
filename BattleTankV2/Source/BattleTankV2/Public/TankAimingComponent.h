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
class AProjectile;

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

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Fire();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Fireing")
	float LaunchSpeed = 10000;

	// TODO move to private for final release
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBluePrint;

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFireingState FireingState = EFireingState::Reloading;

private:

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)override;

	void MoveBarrelTowards(FVector AimDirection);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;


	UPROPERTY(EditDefaultsOnly, Category = "Fireing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
};
