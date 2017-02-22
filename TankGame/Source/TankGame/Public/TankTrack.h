// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	//sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	//Max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000; // assume 40 tonne tank, and 1 g acceleration
	
	
};
