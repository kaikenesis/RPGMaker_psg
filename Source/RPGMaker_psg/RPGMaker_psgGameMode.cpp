#include "RPGMaker_psgGameMode.h"
#include "RPGMaker_psgCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/TowerRpgHudWidget.h"

ARPGMaker_psgGameMode::ARPGMaker_psgGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TowerRPG/Blueprints/Character/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
