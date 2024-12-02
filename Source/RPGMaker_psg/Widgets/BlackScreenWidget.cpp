#include "Widgets/BlackScreenWidget.h"
#include "Animation/WidgetAnimation.h"

void UBlackScreenWidget::NativeConstruct()
{
	
}

void UBlackScreenWidget::PlayAnimFadeInOut()
{
	PlayAnimation(FadeInOut);
}
