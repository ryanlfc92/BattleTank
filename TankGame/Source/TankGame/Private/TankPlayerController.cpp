// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankPlayerController.h"








void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimTowardsCrosshair();
	
}


ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{

	Super::BeginPlay();
	

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller possessing %s."), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());

			//tell controlled tank to aim at this point
	}	
}
//get world location of linetrace through crosshair
//if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
	
}