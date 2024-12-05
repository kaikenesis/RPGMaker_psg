#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerRpgHudWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UTowerRpgHudWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void BeginPlay();

public:
	void SetVisibilityQuestLog(ESlateVisibility InVisibility);
	void SetVisibilityNpcDialogue(ESlateVisibility InVisibility, class UDataTable* inDialogueList = nullptr);
	bool NextNPCDialogue();

protected:
	void AddQuestLog();

private:
	UPROPERTY(meta = (BindWidget))
	class UQuestLogWidget* QuestLog;
	
	UPROPERTY(meta = (BindWidget))
	class UNpcDialogueWidget* NpcDialogue;
};
