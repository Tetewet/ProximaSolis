// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProximaSolisGameMode.h"
#include "ProximaSolisCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProximaSolisGameMode::AProximaSolisGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
