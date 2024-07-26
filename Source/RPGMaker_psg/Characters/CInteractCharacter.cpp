#include "Characters/CInteractCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CInteractionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"

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

	ConstructorHelpers::FClassFinder<UUserWidget> widget(TEXT("/Game/TowerRPG/Widgets/WB_BlackScreen"));
	if (widget.Succeeded())
	{
		BlackScreenWidgetClass = widget.Class;
	}
}

void ACInteractCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
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
	PlayerAdjustment();
	FlashScreen();
}

void ACInteractCharacter::PlayerAdjustment()
{
	FInputModeUIOnly inputMode;
	if (PlayerController != nullptr)
	{
		PlayerController->SetInputMode(inputMode);
	}
}

void ACInteractCharacter::FlashScreen()
{
	UUserWidget* blackScreenWidget = CreateWidget(PlayerController, BlackScreenWidgetClass);
	blackScreenWidget->AddToViewport();
	FLatentActionInfo latentActionInfo;
	UKismetSystemLibrary::Delay(GetWorld(), 0.2f, latentActionInfo);
	
	PlayerController->SetViewTargetWithBlend(Camera->GetOwner());
	FTransform transform;
	float x = PlayerPosition->GetComponentLocation().X;
	float y = PlayerPosition->GetComponentLocation().Y;
	float z = PlayerCharacter->GetRootComponent()->GetComponentLocation().Z;
	transform.SetLocation(FVector(x, y, z));
	
	float roll = PlayerCharacter->GetRootComponent()->GetComponentRotation().Roll;
	float pitch = PlayerCharacter->GetRootComponent()->GetComponentRotation().Pitch;
	float yaw = GetMesh()->GetComponentRotation().Yaw - 90.f;
	transform.SetRotation(FQuat(FRotator(pitch, yaw, roll)));

	PlayerCharacter->GetRootComponent()->SetWorldTransform(transform);
	
	UKismetSystemLibrary::Delay(GetWorld(), 0.2f, latentActionInfo);
	blackScreenWidget->RemoveFromParent();
}

