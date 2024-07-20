#include "Characters/InteractCharacter.h"

AInteractCharacter::AInteractCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

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

