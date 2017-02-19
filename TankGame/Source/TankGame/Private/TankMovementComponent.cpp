// Fill out your copyright notice in the Description page of Project Settings.

#include "TankGame.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}



void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	
	auto ForwardThrow = FVector::DotProduct( AiForwardIntention, TankForward);
	IntendMoveForward(ForwardThrow);
	UE_LOG(LogTemp, Warning, TEXT("ft   %f"), ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AiForwardIntention).Z;
	IntendTurnRight(RightThrow);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{

	
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{


	UE_LOG(LogTemp, Warning, TEXT("Intend Move forward throw: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}
