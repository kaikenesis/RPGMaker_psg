#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestLogWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UQuestLogWidget : public UUserWidget
{
	GENERATED_BODY()
	
public: // Delegate
	UFUNCTION()
	void AddQuestInfo(struct FDataTableRowHandle InQuestInfoDataTable);

protected:
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* QuestContainor;
};
