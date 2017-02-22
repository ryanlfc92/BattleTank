// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "Tank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//no need to protect pointers as added at construction
	

	
}


void ATank::RetrieveBarrelandTurret (UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	TankAimingComponent->Initialise(BarrelToSet, TurretToSet);

	Barrel = BarrelToSet;
	

}




// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
	
}




// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded) 
	
	{

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
		
}