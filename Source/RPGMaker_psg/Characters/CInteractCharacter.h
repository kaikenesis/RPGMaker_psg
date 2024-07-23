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

public:
	virtual void ActivateDialogue_Interface() override;

private: // SceneComponents
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* PlayerPosition;

	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;

private: // ActorComponents
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	class UCInteractionComponent* InteractionComp;

};
