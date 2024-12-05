#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NpcDialogueWidget.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FQuestAcceptedSignature, struct FDataTableRowHandle, InQuestInfoDataTable);

UCLASS()
class RPGMAKER_PSG_API UNpcDialogueWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

public:
	void PlayAnimFadeInResponsse(int buttonCount);
	void PlayAnimFadeOutResponsse(int buttonCount);
	
	void ShowDialogue(class UDataTable* inDialogueList);
	void HideDialogue();
	bool NextDialogue();

	UFUNCTION()
	void OnClickedButton1();
	UFUNCTION()
	void OnClickedButton2();
	UFUNCTION()
	void OnClickedButton3();
	UFUNCTION()
	void OnClickedButton4();

public:
	FQuestAcceptedSignature OnQuestAccepted;

private:
	void Init();
	void DialogueSetting(class UDataTable* inDialogueList);
	void ResponseSetting(struct FDataTableRowHandle inResponse);
	void SetDialogueMessage(TArray<struct FDialogueSettings*> inDialogues);
	void SetCurrentDialogue(struct FDataTableRowHandle inDialogue);
	void SetQuestLog(struct FDataTableRowHandle inDialogue);
	void ShowResponse(int buttonCount);
	void HideResponse(int buttonCount);

public:
	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* FadeInOutResponse;

protected:
	UPROPERTY(meta = (BindWidget))
	class UOverlay* Dialogue;

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
	TArray<struct FDialogueSettings*> CurrentDialogue;
	TArray<struct FResponseMessageSettings*> CurrentResponse;
	int curPage = 0;
};
