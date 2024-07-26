#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BlackScreenWidget.generated.h"

UCLASS()
class RPGMAKER_PSG_API UBlackScreenWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

public:
	void PlayAnimFadeInOut();

public:
	UPROPERTY(BlueprintReadOnly, Transient, meta = (BindWidgetAnim))
	class UWidgetAnimation* FadeInOut;
};
