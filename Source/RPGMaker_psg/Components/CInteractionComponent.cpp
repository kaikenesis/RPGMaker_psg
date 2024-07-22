#include "Components/CInteractionComponent.h"
#include "RPGMaker_psgCharacter.h"

UCInteractionComponent::UCInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ACharacter* character = Cast<ACharacter>(GetOwner());
	if (character != nullptr)
		OwnerCharacter = character;

	ARPGMaker_psgCharacter* playerCharacter = Cast<ARPGMaker_psgCharacter>(OwnerCharacter);
	if (playerCharacter != nullptr)
		bPlayer = true;
}


void UCInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bPlayer == true)
	{

	}
}
