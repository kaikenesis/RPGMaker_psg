#include "RPGMaker_psgCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/BoxComponent.h"
#include "Components/CActionComponent.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"
#include "Components/CInteractionComponent.h"
#include "Interfaces/INPCInteraction.h"
#include "Characters/CInteractCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetSystemLibrary.h"

ARPGMaker_psgCharacter::ARPGMaker_psgCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);

	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->GravityScale = 1.3f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;	
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->SetBoxExtent(FVector(10.f, 30.f, 20.f));

	ActionComp = CreateDefaultSubobject<UCActionComponent>(TEXT("ActionComp"));
	StateComp = CreateDefaultSubobject<UCStateComponent>(TEXT("StateComp"));
	StatusComp = CreateDefaultSubobject<UCStatusComponent>(TEXT("StatusComp"));
}

void ARPGMaker_psgCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ARPGMaker_psgCharacter::OnBeginOverlap_Interaction);
}

void ARPGMaker_psgCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGMaker_psgCharacter::OnMove);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGMaker_psgCharacter::OnLook);
		EnhancedInputComponent->BindAction(DoAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::OnDoAction);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::OnSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ARPGMaker_psgCharacter::OnWalk);
		EnhancedInputComponent->BindAction(AvoidAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::OnAvoid);
		EnhancedInputComponent->BindAction(InteractionAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::OnInteraction);
	}

}

void ARPGMaker_psgCharacter::OnBeginOverlap_Interaction(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UKismetSystemLibrary::DoesImplementInterface(OtherActor, UINPCInteraction::StaticClass()) == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Detected INPCInteraction");
		InteractionActors.Add(OtherActor);
	}
}

void ARPGMaker_psgCharacter::OnMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ARPGMaker_psgCharacter::OnLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ARPGMaker_psgCharacter::OnDoAction(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Attack");
}

void ARPGMaker_psgCharacter::OnSprint(const FInputActionValue& Value)
{
	StatusComp->SetMaxWalkSpeed(800.f);
}

void ARPGMaker_psgCharacter::OnWalk(const FInputActionValue& Value)
{
	StatusComp->SetMaxWalkSpeed(500.f);
}

void ARPGMaker_psgCharacter::OnInteraction(const FInputActionValue& Value)
{
	if (InteractionActors.Num() != 0)
	{
		float distance = 0;
		AActor* targerActor = NULL;
		for (const auto& actor : InteractionActors)
		{
			if (distance < GetDistanceTo(actor))
			{
				targerActor = actor;
				distance = GetDistanceTo(actor);
			}
		}

		ACInteractCharacter* interactCharacter = Cast<ACInteractCharacter>(targerActor);
		if(interactCharacter != nullptr)
			interactCharacter->ActivateDialogue_Interface();
	}
}

void ARPGMaker_psgCharacter::OnAvoid(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Avoid");
}
