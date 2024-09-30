#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CGameInstance.generated.h"

UCLASS()
class RPGMAKER_PSG_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UCGameInstance();

public:
	FORCEINLINE TSubclassOf<class UBlackScreenWidget> GetBlackScreenWidgetClass() { return BlackScreenWidgetClass; }
	FORCEINLINE TSubclassOf<class UTowerRpgHudWidget> GetHUDWidgetClass() { return HUDWidgetClass; }

private:
	TSubclassOf<class UBlackScreenWidget> BlackScreenWidgetClass;
	TSubclassOf<class UTowerRpgHudWidget> HUDWidgetClass;
};
