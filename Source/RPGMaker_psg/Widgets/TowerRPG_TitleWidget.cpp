#include "Widgets/TowerRPG_TitleWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "TowerRPG_TitleWidget.h"

void UTowerRPG_TitleWidget::NativeConstruct()
{
	StartBtn->OnClicked.AddDynamic(this, &UTowerRPG_TitleWidget::OnStartGame);
	EndBtn->OnClicked.AddDynamic(this, &UTowerRPG_TitleWidget::OnEndGame);
}

void UTowerRPG_TitleWidget::OnStartGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Start");
	UE_LOG(LogTemp, Warning, TEXT("Start"));
}

void UTowerRPG_TitleWidget::OnEndGame()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "End");
	UE_LOG(LogTemp, Warning, TEXT("End"));
}
