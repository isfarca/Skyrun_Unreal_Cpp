// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "SimpleProjectCharacter.generated.h"

UCLASS(config=Game)
class ASimpleProjectCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	// Declare variables.
	int direction = 0;
	int frameCount = 0;
	bool canTurnRight = false;
	FVector floorPosition = FVector(0.0f, 0.0f, 0.0f);
	FVector floorDirection = FVector(0.0f, 0.0f, 0.0f);

	// Spring arm that will offset the camera and the camera component that will be our viewpoint.
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;
		UCameraComponent* Camera;

public:
	// Declare variables.
	float BaseTurnRate = 0.0f;
	float BaseLookUpRate = 0.0f;

	// Basic constructor.
	ASimpleProjectCharacter();

protected:
	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

	// Called every frame
	virtual void Tick(float DeltaSeconds);

	// Set direction of the floors.
	void ChangeDirection(float Value);

	// Set new floors in the direction.
	void UpdateFloorDirection(FVector& direction);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
};