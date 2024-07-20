#include "Components/CStatusComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UCStatusComponent::UCStatusComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ACharacter* character = Cast<ACharacter>(GetOwner());
	if (character != nullptr)
		OwnerCharacter = character;
}


void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCStatusComponent::SetMaxWalkSpeed(float InNewSpeed)
{
	OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = InNewSpeed;
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Sprint");
}

