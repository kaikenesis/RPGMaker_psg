#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "QuestWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UQuestWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FORCEINLINE class UTextBlock* GetName() const { return Name; }
	FORCEINLINE class UTextBlock* GetCompleteInfo() const { return CompleteInfo; }
	FORCEINLINE class UTextBlock* GetInfo() const { return Info; }

public:
	void SetName();
	void SetCompleteInfo(bool IsComplete);
	void SetInfo();

protected:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CompleteInfo;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Info;
};
