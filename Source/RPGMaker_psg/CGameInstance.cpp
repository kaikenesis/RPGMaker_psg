#include "CGameInstance.h"
#include "Widgets/BlackScreenWidget.h"
#include "Widgets/TowerRpgHudWidget.h"

UCGameInstance::UCGameInstance()
{
	ConstructorHelpers::FClassFinder<UBlackScreenWidget> widgetAsset(TEXT("/Game/TowerRPG/Widgets/WB_BlackScreen"));
	if (widgetAsset.Succeeded())
	{
		BlackScreenWidgetClass = widgetAsset.Class;
	}

	static ConstructorHelpers::FClassFinder<UTowerRpgHudWidget> hudwidgetAsset(TEXT("/Game/TowerRPG/Widgets/WB_HUD"));
	if (hudwidgetAsset.Succeeded())
	{
		HUDWidgetClass = hudwidgetAsset.Class;
	}
}
