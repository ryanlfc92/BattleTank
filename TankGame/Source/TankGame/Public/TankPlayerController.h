// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;

UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
    //move tank barrel along the crosshair every tick.
	void AimTowardsCrosshair();
	
    bool GetSightRayHitLocation(FVector& HitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;



	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
