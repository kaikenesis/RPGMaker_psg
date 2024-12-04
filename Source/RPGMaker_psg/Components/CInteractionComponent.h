#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGMAKER_PSG_API UCInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	enum class EInputMode
	{
		GameOnly,
		UIOnly,
		GameAndUI,
		MAX
	};

public:	
	UCInteractionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE bool IsPlayDialogue() { return bPlayDialogue; }

public:
	void OnInteraction();
	void AddInteractActor(AActor* InActor);
	void RemoveInteractActor(AActor* InActor);
	void InitWidget();
	
private:
	void PlayerAdjustment(EInputMode inputMode);
	void FlashScreen();

	void ChangeGameToDialogue();
	void ChangeDialogueToGame();
	void SetCameraMove();
	void SetPlayWidget();
	void SetDialogSceneWidget(bool bActive);
	void SetNearlyActor();

	void StartDialogue();
	void FinishDialogue();
	void NextDialogue();

private:
	class ARPGMaker_psgCharacter* PlayerCharacter;
	class APlayerController* PlayerController;

	TArray<class AActor*> InteractionActors;
	class AActor* TargetActor;
	
	class UBlackScreenWidget* BlackScreenWidget;
	TSubclassOf<class UBlackScreenWidget> BlackScreenWidgetClass;
	class UTowerRpgHudWidget* HUDWidget;
	TSubclassOf<class UTowerRpgHudWidget> HUDWidgetClass;
	bool bPlayDialogue = false;
};
