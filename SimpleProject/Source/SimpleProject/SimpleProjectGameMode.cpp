// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SimpleProjectGameMode.h"
#include "SimpleProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASimpleProjectGameMode::ASimpleProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}