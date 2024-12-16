#include "Widgets/TowerRpgHudWidget.h"
#include "Widgets/QuestLogWidget.h"
#include "Widgets/NpcDialogueWidget.h"

void UTowerRpgHudWidget::NativeConstruct()
{
	Super::NativeConstruct();

	NpcDialogue->OnQuestAccepted.AddDynamic(QuestLog, &UQuestLogWidget::AddQuestInfo);
}

void UTowerRpgHudWidget::SetVisibilityQuestLog(ESlateVisibility InVisibility)
{
	QuestLog->SetVisibility(InVisibility);
}

void UTowerRpgHudWidget::SetVisibilityNpcDialogue(ESlateVisibility InVisibility, UDataTable* inDialogueList)
{
	if (InVisibility == ESlateVisibility::Visible)
		NpcDialogue->ShowDialogue(inDialogueList);
	else if(InVisibility == ESlateVisibility::Hidden)
		NpcDialogue->HideDialogue();
}

bool UTowerRpgHudWidget::NextNPCDialogue()
{
	return NpcDialogue->NextDialogue();
}
