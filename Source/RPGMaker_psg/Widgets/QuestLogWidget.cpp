#include "Widgets/QuestLogWidget.h"
#include "Components/VerticalBox.h"
#include "Widgets/QuestWidget.h"
#include "DataTables/CustomDataTables.h"

void UQuestLogWidget::AddQuestInfo(FDataTableRowHandle InQuestInfoDataTable)
{
	TArray<FQuestInfo*> questInfos;
	InQuestInfoDataTable.DataTable->GetAllRows("", questInfos);

	for (const auto widget : QuestContainor->GetAllChildren())
	{
		UQuestWidget* questWidget = Cast<UQuestWidget>(widget);
		if (questWidget != nullptr)
		{
			if (questWidget->IsActive())
			{
				// 퀘스트 code 중복되는지 체크, 중복되면 break
				// 아니면 continue
				if (questWidget->IsAccepted(questInfos[0]->QuestCode)) break;
			}
			else
			{
				// 퀘스트 등록 후 break
				questWidget->SetQuestInfo(InQuestInfoDataTable);
				break;
			}
		}
	}
}
