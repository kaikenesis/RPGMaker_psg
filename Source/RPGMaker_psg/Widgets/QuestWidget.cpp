#include "Widgets/QuestWidget.h"
#include "Components/TextBlock.h"

void UQuestWidget::SetName()
{
	//Name->SetText(FText)
}

void UQuestWidget::SetCompleteInfo(bool IsComplete)
{
	IsComplete ? CompleteInfo->SetVisibility(ESlateVisibility::Visible) : CompleteInfo->SetVisibility(ESlateVisibility::Hidden);
}

void UQuestWidget::SetInfo()
{
	//Info->SetText(FText)
}
