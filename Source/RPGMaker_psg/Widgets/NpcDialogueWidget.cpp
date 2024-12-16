#include "Widgets/NpcDialogueWidget.h"
#include "DataTables/CustomDataTables.h"
#include "Components/VerticalBox.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Animation/WidgetAnimation.h"
#include "Kismet/KismetArrayLibrary.h"

void UNpcDialogueWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Init();
}

void UNpcDialogueWidget::PlayAnimFadeInResponsse(int buttonCount)
{
	ShowResponse(buttonCount);
	PlayAnimationForward(FadeInOutResponse);
}

void UNpcDialogueWidget::PlayAnimFadeOutResponsse(int buttonCount)
{
	float endTime = FadeInOutResponse->GetEndTime();
	FTimerHandle timerResponseHandle;

	PlayAnimationReverse(FadeInOutResponse);
	GetWorld()->GetTimerManager().SetTimer(timerResponseHandle, [&]() { HideResponse(buttonCount); }, endTime, false);
	CurrentResponse.Empty();
}

void UNpcDialogueWidget::ShowDialogue(UDataTable* inDialogueList)
{
	
	Dialogue->SetVisibility(ESlateVisibility::Visible);

	// currentDialogueList로 UMG text변경
	DialogueSetting(inDialogueList);
}

void UNpcDialogueWidget::HideDialogue()
{
	Dialogue->SetVisibility(ESlateVisibility::Hidden);
}

bool UNpcDialogueWidget::NextDialogue()
{
	if (!CurrentResponse.IsEmpty()) return true;

	if (!CurrentDialogue.IsEmpty())
	{
		curPage++;
		if (curPage < CurrentDialogue.Num())
		{
			SetDialogueMessage(CurrentDialogue);
			return true;
			// 대화가 끝일때 선택지 버튼이 있으면 입력을 막고, 선택지 버튼이 없으면 대화종료
		}
		else
			return false;
	}
	return false;
}

void UNpcDialogueWidget::Init()
{
	ResponseButton4->SetVisibility(ESlateVisibility::Hidden);
	ResponseButton3->SetVisibility(ESlateVisibility::Hidden);
	ResponseButton2->SetVisibility(ESlateVisibility::Hidden);
	ResponseButton1->SetVisibility(ESlateVisibility::Hidden);
	ResponseContainor->SetVisibility(ESlateVisibility::Hidden);
	Dialogue->SetVisibility(ESlateVisibility::Visible);

	ResponseButton1->OnClicked.AddDynamic(this, &UNpcDialogueWidget::OnClickedButton1);
	ResponseButton2->OnClicked.AddDynamic(this, &UNpcDialogueWidget::OnClickedButton2);
	ResponseButton3->OnClicked.AddDynamic(this, &UNpcDialogueWidget::OnClickedButton3);
	ResponseButton4->OnClicked.AddDynamic(this, &UNpcDialogueWidget::OnClickedButton4);
}

void UNpcDialogueWidget::DialogueSetting(UDataTable* inDialogueList)
{
	if (inDialogueList == nullptr) return;
	CurrentDialogueList = inDialogueList;
	
	TArray<FDialogueList*> list;
	CurrentDialogueList->GetAllRows("", list);

	TArray<FDialogueSettings*> dialogues;
	if (!list.IsEmpty())
	{
		// list[i] -> i값은 플레이어에서 해당 NPC와 어느정도 대화를 진행했었는지 저장하는 변수를 만들어서 관리
		list[0]->DialogueHandle.DataTable->GetAllRows("", dialogues);
		CurrentDialogue = dialogues;
	}
	
	if (!dialogues.IsEmpty())
	{
		// dialogues[i] -> i값은 여기에서 변수로 따로 만들어 입력키를 누를때마다 값이 증가하여 다음 메시지가 출력가능하도록 관리
		curPage = 0;
		SetDialogueMessage(dialogues);
	}
}

void UNpcDialogueWidget::ResponseSetting(FDataTableRowHandle inResponse)
{
	if (inResponse.IsNull() == true) return;

	inResponse.DataTable->GetAllRows("", CurrentResponse);
	if (!CurrentResponse.IsEmpty())
	{
		PlayAnimFadeInResponsse(CurrentResponse.Num());
	}
}

void UNpcDialogueWidget::SetDialogueMessage(TArray<struct FDialogueSettings*> inDialogues)
{
	ChatBox->SetText(inDialogues[curPage]->Message);
	if (inDialogues[curPage]->ResponseHandle.DataTable != nullptr)
	{
		ResponseSetting(inDialogues[curPage]->ResponseHandle);
	}
}

void UNpcDialogueWidget::SetCurrentDialogue(FDataTableRowHandle inDialogue)
{
	if (inDialogue.DataTable != nullptr)
	{
		inDialogue.DataTable->GetAllRows("", CurrentDialogue);
	}
}

void UNpcDialogueWidget::SetQuestLog(FDataTableRowHandle inDialogue)
{
	if (inDialogue.DataTable != nullptr && OnQuestAccepted.IsBound())
	{
		OnQuestAccepted.Broadcast(inDialogue);
	}
}

void UNpcDialogueWidget::ShowResponse(int buttonCount)
{
	switch (buttonCount)
	{
	case 4:
	{
		ResponseButton4->SetVisibility(ESlateVisibility::Visible);
		ResponseText4->SetText(CurrentResponse[3]->PlayerResponse);
	}
	case 3:
	{
		ResponseButton3->SetVisibility(ESlateVisibility::Visible);
		ResponseText3->SetText(CurrentResponse[2]->PlayerResponse);
	}
	case 2:
	{
		ResponseButton2->SetVisibility(ESlateVisibility::Visible);
		ResponseText2->SetText(CurrentResponse[1]->PlayerResponse);
	}
	case 1:
	{
		ResponseButton1->SetVisibility(ESlateVisibility::Visible);
		ResponseText1->SetText(CurrentResponse[0]->PlayerResponse);
	}
	default: break;
	}

	ResponseContainor->SetVisibility(ESlateVisibility::Visible);
}

void UNpcDialogueWidget::HideResponse(int buttonCount)
{
	switch (buttonCount)
	{
	case 4: ResponseButton4->SetVisibility(ESlateVisibility::Hidden);
	case 3:	ResponseButton3->SetVisibility(ESlateVisibility::Hidden);
	case 2:	ResponseButton2->SetVisibility(ESlateVisibility::Hidden);
	case 1:	ResponseButton1->SetVisibility(ESlateVisibility::Hidden);
	default: break;
	}

	ResponseContainor->SetVisibility(ESlateVisibility::Hidden);
}

void UNpcDialogueWidget::OnClickedButton1()
{
	if (CurrentResponse.Num() <= 0) return;

	SetCurrentDialogue(CurrentResponse[0]->DialogueHandle);
	if (CurrentResponse[0]->MessageButton == EMessageButton::AccpetQuest)
		SetQuestLog(CurrentResponse[0]->QuestInfoHandle);
	PlayAnimFadeOutResponsse(CurrentResponse.Num());
	NextDialogue();
}

void UNpcDialogueWidget::OnClickedButton2()
{
	if (CurrentResponse.Num() <= 0) return;

	SetCurrentDialogue(CurrentResponse[1]->DialogueHandle);
	if (CurrentResponse[1]->MessageButton == EMessageButton::AccpetQuest)
		SetQuestLog(CurrentResponse[1]->QuestInfoHandle);
	PlayAnimFadeOutResponsse(CurrentResponse.Num());
	NextDialogue();
}

void UNpcDialogueWidget::OnClickedButton3()
{
	if (CurrentResponse.Num() <= 0) return;

	SetCurrentDialogue(CurrentResponse[2]->DialogueHandle);
	if (CurrentResponse[2]->MessageButton == EMessageButton::AccpetQuest)
		SetQuestLog(CurrentResponse[2]->QuestInfoHandle);
	PlayAnimFadeOutResponsse(CurrentResponse.Num());
	NextDialogue();
}

void UNpcDialogueWidget::OnClickedButton4()
{
	if (CurrentResponse.Num() <= 0) return;

	SetCurrentDialogue(CurrentResponse[3]->DialogueHandle);
	if (CurrentResponse[3]->MessageButton == EMessageButton::AccpetQuest)
		SetQuestLog(CurrentResponse[3]->QuestInfoHandle);
	PlayAnimFadeOutResponsse(CurrentResponse.Num());
	NextDialogue();
}
