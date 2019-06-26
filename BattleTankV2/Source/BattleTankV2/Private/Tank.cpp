// CopyRight Maximum LTD.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	//test
	Super::BeginPlay(); // Needed for Blueprint code

}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

		if (IsReloaded)
		{
			if (CanTankFire)
			{
				auto Projectile = GetWorld()->SpawnActor<AProjectile>(
					ProjectileBluePrint,
					Barrel->GetSocketLocation(FName("Projectile")),
					Barrel->GetSocketRotation(FName("Projectile"))
					);

				Projectile->LaunchProjectile(9999);
				LastFireTime = FPlatformTime::Seconds();
			}
		}
}

