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

	// currentDialogueList�� UMG text����
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
			// ��ȭ�� ���϶� ������ ��ư�� ������ �Է��� ����, ������ ��ư�� ������ ��ȭ����
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
		// list[i] -> i���� �÷��̾�� �ش� NPC�� ������� ��ȭ�� �����߾����� �����ϴ� ������ ���� ����
		list[0]->DialogueHandles.DataTable->GetAllRows("", dialogues);
		CurrentDialogue = dialogues;
	}
	
	if (!dialogues.IsEmpty())
	{
		// dialogues[i] -> i���� ���⿡�� ������ ���� ����� �Է�Ű�� ���������� ���� �����Ͽ� ���� �޽����� ��°����ϵ��� ����
		curPage = 0;
		ChatBox->SetText(dialogues[curPage]->Message);
	}
}
