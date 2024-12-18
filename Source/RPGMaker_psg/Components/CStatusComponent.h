#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPGMAKER_PSG_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatusComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void SetMaxWalkSpeed(float InNewSpeed);

private:
	class ACharacter* OwnerCharacter;

	UPROPERTY(EditDefaultsOnly, Category = "Status")
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, Category = "Status")
	float MaxStamina;
};
