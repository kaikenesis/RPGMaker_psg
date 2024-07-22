#include "Characters/InteractCharacter.h"
#include "Components/CInteractionComponent.h"

AInteractCharacter::AInteractCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	InteractionComp = CreateDefaultSubobject<UCInteractionComponent>(TEXT("InteractionComp"));
}

void AInteractCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

