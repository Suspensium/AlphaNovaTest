// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Purifier.h"

ACPP_Purifier::ACPP_Purifier() : ACPP_Target() {}

void ACPP_Purifier::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check player collision first
	Super::OnActorBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	// If purifier is painted, it paints collided actors except for purifier
	if (bPainted)
	{
		ACPP_DefaultTarget* HitTarget{ Cast<ACPP_DefaultTarget>(OtherActor) };
		if (HitTarget)
			HitTarget->Paint();
	}
	// If purifier is not painted, it removes paint from collided actors
	else
	{
		ACPP_Target* HitTarget{ Cast<ACPP_Target>(OtherActor) };
		if (HitTarget)
			HitTarget->RemovePaint();
	}
}
