// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SimpleProjectCharacter.h"
#include "Engine.h"
#include "Floor.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// ASimpleProjectCharacter

ASimpleProjectCharacter::ASimpleProjectCharacter()
{
	// Debug output.
	GEngine->AddOnScreenDebugMessage(-1, 300.0f, FColor::Blue, TEXT("The Game is started!"));

	// Set begin floor position and floor direction.
	floorPosition = FVector(2000, 0, -200);
	floorDirection = FVector(1, 0, 0);

	// Set size for collision capsule.
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Set our turn rates for input.
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement.
	GetCharacterMovement()->bOrientRotationToMovement = true; 	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	GetCharacterMovement()->MaxWalkSpeed = 800.0F;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 54.0f));
	SpringArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 525.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;

	// Create the chase camera component.
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	Camera->AttachTo(SpringArm, USpringArmComponent::SocketName);
	Camera->SetRelativeRotation(FRotator(10.0f, 0.0f, 0.0f));
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;

	// Direction player is facing.
	direction = 0;

	// Used to prevent the player turning more than ninety degrees on a single key press.
	canTurnRight = true;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASimpleProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//InputComponent->BindAxis("MoveForward", this, &AJungleRunCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASimpleProjectCharacter::ChangeDirection);//new 3

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASimpleProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASimpleProjectCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASimpleProjectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASimpleProjectCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ASimpleProjectCharacter::OnResetVR);
}


void ASimpleProjectCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ASimpleProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ASimpleProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ASimpleProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASimpleProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASimpleProjectCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASimpleProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void ASimpleProjectCharacter::Tick(float DeltaSeconds)
{
	// Declare variables.
	AFloor* myFloor;
	UWorld* world = GetWorld();
	FVector spawnLocation;
	FRotator floorRotation;

	Super::Tick(DeltaSeconds);

	// Set the direction for the floors.
	if (direction == 0)
		MoveForward(1);
	else if (direction == 2)
		MoveForward(-1);
	else if (direction == 1)
		MoveRight(1);
	else if (direction == 3)
		MoveRight(-1);

	frameCount++;

	// Set floors in the level.
	if (world && frameCount > 20)
	{
		frameCount = 0;
		spawnLocation = floorPosition;
		floorPosition += floorDirection * 400;

		UpdateFloorDirection(floorDirection);

		floorRotation = FRotator(0, 0, 0);
		myFloor = world->SpawnActor<AFloor>(spawnLocation, floorRotation);
	}
}

void ASimpleProjectCharacter::ChangeDirection(float value)
{
	// Change direction, when you have a value and turn right.
	if (value != 0 && canTurnRight) 
	{
		canTurnRight = false;
		direction += value;

		if (direction > 3)
			direction = 0;
		else if (direction < 0)
			direction = 3;
	}
	else if (value == 0)
		canTurnRight = true;
}

void ASimpleProjectCharacter::UpdateFloorDirection(FVector& direction)
{
	// Declare variables
	float change = 0.0f;
	int randNum1 = rand() % 15;
	int randNum2 = rand() % 10;

	// Set change.
	if (randNum2 > 7)
		change = 0.1f;
	else if (randNum2 > 4)
		change = -0.1f;

	// Set the direction of the floors.
	switch (randNum1) 
	{
		case 0:
			if (floorDirection.Y != -1)
				floorDirection = FVector(0, 1, change);
			break;
		case 4:
			if (floorDirection.X != -1)
				floorDirection = FVector(1, 0, change);
			break;
		case 8:
			if (floorDirection.X != 1)
				floorDirection = FVector(-1, 0, change);
			break;
		case 12:
			if (floorDirection.Y != 1)
				floorDirection = FVector(0, -1, change);
			break;
	}
}