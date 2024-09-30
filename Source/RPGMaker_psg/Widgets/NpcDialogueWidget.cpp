#include "Widgets/NpcDialogueWidget.h"
#include "Components/VerticalBox.h"
#include "Components/Overlay.h"
#include "Animation/WidgetAnimation.h"

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

void UNpcDialogueWidget::ShowDialog()
{
	Dialog->SetVisibility(ESlateVisibility::Visible);
}

void UNpcDialogueWidget::HideDialog()
{
	Dialog->SetVisibility(ESlateVisibility::Hidden);
}

void UNpcDialogueWidget::Init()
{
	ResponseContainor->SetVisibility(ESlateVisibility::Hidden);
	Dialog->SetVisibility(ESlateVisibility::Visible);
}
