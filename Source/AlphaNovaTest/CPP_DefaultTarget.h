// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Target.h"
#include "CPP_DefaultTarget.generated.h"

/**
 *
 */
UCLASS()
class ALPHANOVATEST_API ACPP_DefaultTarget : public ACPP_Target
{
	GENERATED_BODY()

public:
	ACPP_DefaultTarget();

	void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override final;
};
