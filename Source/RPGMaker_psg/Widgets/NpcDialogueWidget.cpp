#include "Widgets/NpcDialogueWidget.h"
#include "DataTables/CustomDataTables.h"
#include "Components/VerticalBox.h"
#include "Components/Overlay.h"
#include "Components/TextBlock.h"

void UNpcDialogueWidget::NativeConstruct()
{
	Init();
}

void UNpcDialogueWidget::PlayAnimFadeInResponsse()
{
	ResponseContainor->SetVisibility(ESlateVisibility::Visible);
	PlayAnimationForward(FadeInOutResponse);
}

void UNpcDialogueWidget::PlayAnimFadeOutResponsse()
{
	PlayAnimationReverse(FadeInOutResponse);
	ResponseContainor->SetVisibility(ESlateVisibility::Hidden);
}

void UNpcDialogueWidget::ShowDialogue(UDataTable* inDialogueList)
{
	
	Dialog->SetVisibility(ESlateVisibility::Visible);

	// currentDialogueList로 UMG text변경
	DialogueSetting(inDialogueList);
}

void UNpcDialogueWidget::HideDialogue()
{
	Dialog->SetVisibility(ESlateVisibility::Hidden);
}

bool UNpcDialogueWidget::NextDialogue()
{
	if (!CurrentDialogue.IsEmpty())
	{
		curPage++;
		if (curPage < CurrentDialogue.Num())
		{
			ChatBox->SetText(CurrentDialogue[curPage]->Message);
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
	ResponseContainor->SetVisibility(ESlateVisibility::Hidden);
	Dialog->SetVisibility(ESlateVisibility::Visible);
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
		list[0]->DialogueHandles.DataTable->GetAllRows("", dialogues);
		CurrentDialogue = dialogues;
	}
	
	if (!dialogues.IsEmpty())
	{
		// dialogues[i] -> i값은 여기에서 변수로 따로 만들어 입력키를 누를때마다 값이 증가하여 다음 메시지가 출력가능하도록 관리
		curPage = 0;
		ChatBox->SetText(dialogues[curPage]->Message);
	}
}
