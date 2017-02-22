// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKGAME_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 10;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxElevationDegree = 40;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MinElevationDegree = -5;

};
