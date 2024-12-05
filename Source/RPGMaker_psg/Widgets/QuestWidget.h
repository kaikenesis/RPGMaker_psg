#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestWidget.generated.h"



UCLASS()
class RPGMAKER_PSG_API UQuestWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

public:
	FORCEINLINE bool IsActive() { return bActive; }

public:
	void SetQuestInfo(struct FDataTableRowHandle InQuestInfoDataTable);
	void SetName(FText questName);
	void SetCompleteInfo(bool IsComplete);
	void SetInfo(FText questInfo);

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CompleteInfo;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Info;

private:
	bool bActive;
};
