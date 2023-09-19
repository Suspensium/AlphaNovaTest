// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_DefaultTarget.h"

ACPP_DefaultTarget::ACPP_DefaultTarget() : ACPP_Target() {}

void ACPP_DefaultTarget::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check player collision first
	Super::OnActorBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	// If default target is not painted, it does not paint anything
	if (!bPainted) return;

	// If collided actor is default target && this actor is painted, then paint collided actor
	// Still it can not paint purifier
	ACPP_DefaultTarget* HitTarget{ Cast<ACPP_DefaultTarget>(OtherActor) };
	if (HitTarget)
		HitTarget->Paint();
}