#include "RPGMaker_psgCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

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

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f;	
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

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
}

void ARPGMaker_psgCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARPGMaker_psgCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARPGMaker_psgCharacter::Look);
		EnhancedInputComponent->BindAction(DoAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::DoSomething);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::OnSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ARPGMaker_psgCharacter::OnWalk);
		EnhancedInputComponent->BindAction(AvoidAction, ETriggerEvent::Started, this, &ARPGMaker_psgCharacter::Avoid);
	}

}

void ARPGMaker_psgCharacter::Move(const FInputActionValue& Value)
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

void ARPGMaker_psgCharacter::Look(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ARPGMaker_psgCharacter::DoSomething(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Attack");
}

void ARPGMaker_psgCharacter::OnSprint(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "SprintStart");
	GetCharacterMovement()->MaxWalkSpeed = 800.f;
}

void ARPGMaker_psgCharacter::OnWalk(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "SprintEnd");
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

void ARPGMaker_psgCharacter::Avoid(const FInputActionValue& Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "Avoid");
}




