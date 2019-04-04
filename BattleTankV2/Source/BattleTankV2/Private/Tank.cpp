// CopyRight Maximum LTD.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay(); // Needed for Blueprint code
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

		if (Barrel && IsReloaded)
		{
			if (CanTankFire)
			{
				auto Projectile = GetWorld()->SpawnActor<AProjectile>(
					ProjectileBluePrint,
					Barrel->GetSocketLocation(FName("Projectile")),
					Barrel->GetSocketRotation(FName("Projectile"))
					);

				Projectile->LaunchProjectile(LaunchSpeed);
				LastFireTime = FPlatformTime::Seconds();
			}
		}
}

