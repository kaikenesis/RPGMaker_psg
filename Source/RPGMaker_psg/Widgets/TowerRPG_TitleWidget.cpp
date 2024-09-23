#include "Widgets/TowerRPG_TitleWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "TowerRPG_TitleWidget.h"
#include "Kismet/GameplayStatics.h"

void UTowerRPG_TitleWidget::NativeConstruct()
{
	StartBtn->OnClicked.AddDynamic(this, &UTowerRPG_TitleWidget::OnStartGame);
	EndBtn->OnClicked.AddDynamic(this, &UTowerRPG_TitleWidget::OnEndGame);
}

void UTowerRPG_TitleWidget::OnStartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), L"/Game/TowerRPG/Maps/MainWorld");
}

void UTowerRPG_TitleWidget::OnEndGame()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), UGameplayStatics::GetPlayerController(GetWorld(), 0), EQuitPreference::Quit, false);
}
