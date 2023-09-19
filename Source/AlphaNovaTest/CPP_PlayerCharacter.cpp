// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PlayerCharacter.h"

// Sets default values
ACPP_PlayerCharacter::ACPP_PlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	CapsuleComponent = GetComponentByClass<UCapsuleComponent>();
	CameraComponent = GetComponentByClass<UCameraComponent>();
}

// Called every frame
void ACPP_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACPP_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACPP_PlayerCharacter::LookAround(float X, float Y)
{
	AddControllerYawInput(X);
	AddControllerPitchInput(Y);
}

void ACPP_PlayerCharacter::Move(float X, float Y)
{
	if (bJumping) return;

	FVector ForceForward{ (RotationSpeed * Y) * CameraComponent->GetForwardVector() };
	FVector ForceRight{ (RotationSpeed * X) * CameraComponent->GetRightVector() };

	CapsuleComponent->AddForce(ForceForward, NAME_None, true);
	CapsuleComponent->AddForce(ForceRight, NAME_None, true);
}

void ACPP_PlayerCharacter::PhysicalJump()
{
	if (bJumping) return;

	bJumping = true;
	FVector ImpulseUpward{ 0, 0, JumpHeight };

	CapsuleComponent->AddImpulse(ImpulseUpward, NAME_None, true);
}