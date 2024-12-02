#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NpcDialogueWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UNpcDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

public:
	void PlayAnimFadeInResponsse();
	void PlayAnimFadeOutResponsse();
	
	void ShowDialog(class UDataTable* inDialogueList);
	void HideDialog();

private:
	void Init();

public:
	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* FadeInOutResponse;

protected:
	UPROPERTY(meta = (BindWidget))
	class UOverlay* Dialog;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ChatBox;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ResponseContainor;

	UPROPERTY(meta = (BindWidget))
	class UButton* ResponseButton1;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResponseText1;

	UPROPERTY(meta = (BindWidget))
	class UButton* ResponseButton2;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResponseText2;

	UPROPERTY(meta = (BindWidget))
	class UButton* ResponseButton3;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResponseText3;

	UPROPERTY(meta = (BindWidget))
	class UButton* ResponseButton4;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ResponseText4;

private:
	class UDataTable* CurrentDialogueList;
};
