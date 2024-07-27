#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGMAKER_PSG_API UCInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCInteractionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void OnInteraction();
	void AddInteractActor(AActor* InActor);
	void RemoveInteractActor(AActor* InActor);
	void PlayerAdjustment();
	void FlashScreen();
	void SetCameraMove();
	void CreateInteractionWidget();
	
private:
	void SetNearlyActor();

private:
	class ARPGMaker_psgCharacter* PlayerCharacter;
	class APlayerController* PlayerController;

	TArray<class AActor*> InteractionActors;
	class AActor* TargetActor;
	
	class UBlackScreenWidget* BlackScreenWidget;
	TSubclassOf<class UBlackScreenWidget> BlackScreenWidgetClass;
};
