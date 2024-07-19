#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerRPG_TitleWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UTowerRPG_TitleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

public:
	UFUNCTION()
	void OnStartGame();
	
	UFUNCTION()
	void OnEndGame();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* StartBtn;

	UPROPERTY(meta = (BindWidget))
	class UButton* EndBtn;

	UPROPERTY(meta = (BindWidget))
	class UImage* BackGround;
};
