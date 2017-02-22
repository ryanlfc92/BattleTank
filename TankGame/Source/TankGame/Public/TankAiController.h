// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class TANKGAME_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:
	
	    virtual void Tick(float DeltaSeconds) override;
	    
		void BeginPlay()override;
		
		UPROPERTY(EditDefaultsOnly, Category = "Setup")
			float AcceptanceRadius = 1500;
	
	
	
};
