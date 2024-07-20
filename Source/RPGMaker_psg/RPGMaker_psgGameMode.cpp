// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGMaker_psgGameMode.h"
#include "RPGMaker_psgCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPGMaker_psgGameMode::ARPGMaker_psgGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TowerRPG/Blueprints/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
