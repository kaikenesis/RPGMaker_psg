#include "Widgets/TowerRpgHudWidget.h"
#include "Widgets/QuestLogWidget.h"
#include "Widgets/NpcDialogueWidget.h"

void UTowerRpgHudWidget::SetVisibilityQuestLog(ESlateVisibility InVisibility)
{
	QuestLog->SetVisibility(InVisibility);
}

void UTowerRpgHudWidget::SetVisibilityNpcDialogue(ESlateVisibility InVisibility, UDataTable* inDialogueList)
{
	if (InVisibility == ESlateVisibility::Visible)
		NpcDialogue->ShowDialog(inDialogueList);
	else if(InVisibility == ESlateVisibility::Hidden)
		NpcDialogue->HideDialog();
}
