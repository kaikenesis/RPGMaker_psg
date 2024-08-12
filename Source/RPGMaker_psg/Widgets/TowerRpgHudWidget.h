#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TowerRpgHudWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UTowerRpgHudWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE class UQuestLogWidget* GetQuestLog() const { return QuestLog; }
	FORCEINLINE class UNpcDialogueWidget* GetNpcDialogue() const { return NpcDialogue; }

public:
	void SetVisibilityQuestLog(ESlateVisibility InVisibility);
	void SetVisibilityNpcDialogue(ESlateVisibility InVisibility);

private:
	UPROPERTY(meta = (BindWidget))
	class UQuestLogWidget* QuestLog;
	
	UPROPERTY(meta = (BindWidget))
	class UNpcDialogueWidget* NpcDialogue;
};
