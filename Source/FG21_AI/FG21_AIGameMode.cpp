// Copyright Epic Games, Inc. All Rights Reserved.

#include "FG21_AIGameMode.h"
#include "FG21_AICharacter.h"
#include "UObject/ConstructorHelpers.h"

AFG21_AIGameMode::AFG21_AIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
