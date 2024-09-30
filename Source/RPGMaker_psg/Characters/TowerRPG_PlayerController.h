#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TowerRPG_PlayerController.generated.h"

UCLASS()
class RPGMAKER_PSG_API ATowerRPG_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATowerRPG_PlayerController();

	virtual void BeginPlay() override;

private:
	void Init();

public:
	void SetInputModeUIOnly();
	void SetInputModeGameOnly();
};
