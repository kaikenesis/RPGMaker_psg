#include "Widgets/QuestLogWidget.h"
#include "Components/VerticalBox.h"
#include "Widgets/QuestWidget.h"
#include "DataTables/CustomDataTables.h"

void UQuestLogWidget::AddQuestInfo(FDataTableRowHandle InQuestInfoDataTable)
{
	for (const auto widget : QuestContainor->GetAllChildren())
	{
		UQuestWidget* questWidget = Cast<UQuestWidget>(widget);
		if (questWidget != nullptr && questWidget->IsActive() == false)
		{
			questWidget->SetQuestInfo(InQuestInfoDataTable);
			break;
		}
	}
}
