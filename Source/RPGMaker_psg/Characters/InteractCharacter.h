#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InteractCharacter.generated.h"

UCLASS()
class RPGMAKER_PSG_API AInteractCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AInteractCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
