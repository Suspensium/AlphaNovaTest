// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_PlayerCharacter.generated.h"

UCLASS()
class ALPHANOVATEST_API ACPP_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPP_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UCapsuleComponent* CapsuleComponent;
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float RotationSpeed{ 200.0f };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float JumpHeight{ 500.0f };
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	bool bJumping{ false };

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Mouse movement
	UFUNCTION(BlueprintCallable, Category = "Physics")
	virtual void LookAround(float X, float Y);

	// Character movement
	UFUNCTION(BlueprintCallable, Category = "Physics")
	virtual void Move(float X, float Y);

	// Jumping
	UFUNCTION(BlueprintCallable, Category = "Physics")
	virtual void PhysicalJump();
};
