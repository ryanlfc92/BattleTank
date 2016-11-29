// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGame.h"
#include "TankAiController.h"
#include "Tank.h"


void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(GetPlayerTank())
	{
		//TODO Move toward player
		//Aim towards Player Location
		auto HitLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(HitLocation);

		//Fire if ready
	}

	

}

ATank* ATankAiController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}


void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player tankk not found."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ai controller found player: %s."), *(PlayerTank->GetName()));
	}
}

