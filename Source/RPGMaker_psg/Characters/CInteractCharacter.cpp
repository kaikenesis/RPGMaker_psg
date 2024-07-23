#include "Characters/CInteractCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CInteractionComponent.h"

ACInteractCharacter::ACInteractCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerPosition = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerPosition"));
	PlayerPosition->SetupAttachment(GetMesh());
	PlayerPosition->SetRelativeLocation(FVector(0.f, 150.f, 0.f));
	PlayerPosition->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));
	PlayerPosition->SetRelativeScale3D(FVector(0.25f));
	PlayerPosition->bHiddenInGame = true;
	PlayerPosition->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);

	InteractionComp = CreateDefaultSubobject<UCInteractionComponent>(TEXT("InteractionComp"));

}

void ACInteractCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACInteractCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACInteractCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACInteractCharacter::ActivateDialogue_Interface()
{
}

