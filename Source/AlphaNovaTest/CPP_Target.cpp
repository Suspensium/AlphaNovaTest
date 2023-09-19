// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Target.h"

// Sets default values
ACPP_Target::ACPP_Target()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACPP_Target::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent = GetComponentByClass<UBoxComponent>();
	MeshComponent = GetComponentByClass<UStaticMeshComponent>();

	// Binds MoveRandomly function to delegate
	MoveTimerDelegate.BindUObject(this, &ACPP_Target::MoveRandomly, RandomImpulseLowerBound, RandomImpulseUpperBound);
	// Runs MoveRandomly function every X seconds
	GetWorldTimerManager().SetTimer(MoveTimerHandle, MoveTimerDelegate, MoveCooldown, true);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Target::OnActorBeginOverlap);
}

// Called every frame
void ACPP_Target::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Target::Paint()
{
	if (bPainted) return;

	MeshComponent->SetMaterial(0, PaintedMaterial);
	bPainted = true;
}

void ACPP_Target::RemovePaint()
{
	if (!bPainted) return;

	MeshComponent->SetMaterial(0, UnpaintedMaterial);
	bPainted = false;
}

void ACPP_Target::MoveRandomly(float ImpulseLowerBound, float ImpulseUpperBound)
{
	if (!bMoving) return;

	float Impulse = FMath::FRandRange(ImpulseLowerBound, ImpulseUpperBound);
	FVector RandomDestination = { FMath::FRandRange(-1.f, 1.f), FMath::FRandRange(-1.f, 1.f), FMath::FRand() };

	BoxComponent->AddImpulse(Impulse * RandomDestination, NAME_None, true);
}

void ACPP_Target::OnActorBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ACPP_PlayerCharacter::StaticClass()) && !bPainted)
	{
		ACPP_Target::Paint();
		return;
	}
}