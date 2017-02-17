// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGame.h"
#include "TankAiController.h"
#include "Tank.h"


void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
		//TODO Move toward player

	{
		//aim towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//ai(this) fire
		ControlledTank->Fire();
		
	}

}

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
	
	
}

