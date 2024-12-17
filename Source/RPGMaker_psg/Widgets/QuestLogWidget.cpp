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
				// ����Ʈ code �ߺ��Ǵ��� üũ, �ߺ��Ǹ� break
				// �ƴϸ� continue
				if (questWidget->IsAccepted(questInfos[0]->QuestCode)) break;
			}
			else
			{
				// ����Ʈ ��� �� break
				questWidget->SetQuestInfo(InQuestInfoDataTable);
				break;
			}
		}
	}
}
