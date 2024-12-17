#include "Widgets/QuestWidget.h"
#include "Components/TextBlock.h"
#include "DataTables/CustomDataTables.h"

void UQuestWidget::NativeConstruct()
{
	if (bActive == false)
	{
		SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		SetVisibility(ESlateVisibility::Visible);
	}
}

void UQuestWidget::SetQuestInfo(FDataTableRowHandle InQuestInfoDataTable)
{
	TArray<FQuestInfo*> questInfos;
	InQuestInfoDataTable.DataTable->GetAllRows("", questInfos);

	code = questInfos[0]->QuestCode;
	Name->SetText(questInfos[0]->QuestName);
	Info->SetText(questInfos[0]->QuestInfo);
	SetVisibility(ESlateVisibility::Visible);
	bActive = true;
}

void UQuestWidget::SetName(FText questName)
{
	Name->SetText(questName);
}

void UQuestWidget::SetCompleteInfo(bool IsComplete)
{
	IsComplete ? CompleteInfo->SetVisibility(ESlateVisibility::Visible) : CompleteInfo->SetVisibility(ESlateVisibility::Hidden);
}

void UQuestWidget::SetInfo(FText questInfo)
{
	Info->SetText(questInfo);
}
