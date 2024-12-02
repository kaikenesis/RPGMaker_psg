#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/INPCInteraction.h"
#include "CInteractCharacter.generated.h"

UCLASS()
class RPGMAKER_PSG_API ACInteractCharacter : public ACharacter, public IINPCInteraction
{
	GENERATED_BODY()

public:
	ACInteractCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public: // Interface
	virtual void ActivateDialogue_Interface() override;

public:
	FORCEINLINE class UCameraComponent* GetSceneCamera() { return Camera; }
	FORCEINLINE FVector GetPlayerPosition() { return PlayerPosition->GetComponentLocation(); }
	FORCEINLINE class UDataTable* GetDialogueList() { return CurrentDialogueList; }

public:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	class UDataTable* DefaultsDialogueList;

private: // SceneComponents
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* PlayerPosition;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;

	class UDataTable* CurrentDialogueList;
};
