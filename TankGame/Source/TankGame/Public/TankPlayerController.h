// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
    //move tank barrel along the crosshair every tick.
	void AimTowardsCrosshair();
	
	
	private:
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
