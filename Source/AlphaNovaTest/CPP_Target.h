// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/BoxComponent.h>
#include "CPP_PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "CPP_Target.generated.h"

UCLASS(ABSTRACT)
class ALPHANOVATEST_API ACPP_Target : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPP_Target();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Is target painted
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	bool bPainted{ false };

	// Is moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor/Physics")
	bool bMoving{ true };

	// Materials of actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* UnpaintedMaterial;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* PaintedMaterial;

	// How much time before moving
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor/Time")
	float MoveCooldown{ 1.f };
	// The lowest impulse with which it can be pushed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor/Physics")
	float RandomImpulseLowerBound{ 100.0f };
	// The highest impulse with which it can be pushed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor/Physics")
	float RandomImpulseUpperBound{ 500.0f };

	class UStaticMeshComponent* MeshComponent;
	class UBoxComponent* BoxComponent;

	// Timer fields
	FTimerHandle MoveTimerHandle;
	FTimerDelegate MoveTimerDelegate;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Moves actor in random direction
	void MoveRandomly(float ImpulseLowerBound, float ImpulseUpperBound);

	// Paint actor
	void Paint();

	// Removes paint on actor
	void RemovePaint();

	// On actors overlap
	UFUNCTION()
	virtual void OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};