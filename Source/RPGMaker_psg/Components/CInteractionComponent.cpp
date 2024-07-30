#include "Components/CInteractionComponent.h"
#include "Components/StaticMeshComponent.h"
#include "RPGMaker_psgCharacter.h"
#include "Camera/CameraComponent.h"
#include "Characters/CInteractCharacter.h"
#include "Widgets/BlackScreenWidget.h"
#include "Kismet/GameplayStatics.h"

UCInteractionComponent::UCInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ARPGMaker_psgCharacter* character = Cast<ARPGMaker_psgCharacter>(GetOwner());
	if (character != nullptr)
	{
		PlayerCharacter = character;
	}

	ConstructorHelpers::FClassFinder<UBlackScreenWidget> widgetAsset(TEXT("/Game/TowerRPG/Widgets/WB_BlackScreen"));
	if (widgetAsset.Succeeded())
	{
		BlackScreenWidgetClass = widgetAsset.Class;
	}
}


void UCInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerController = PlayerCharacter->GetLocalViewingPlayerController();
	BlackScreenWidget = Cast<UBlackScreenWidget>(CreateWidget(PlayerController, BlackScreenWidgetClass));
	BlackScreenWidget->AddToViewport();
	BlackScreenWidget->SetVisibility(ESlateVisibility::Hidden);
}


void UCInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCInteractionComponent::OnInteraction()
{
	if (InteractionActors.Num() != 0)
	{
		SetNearlyActor();

		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "OnInteraction");
		ACInteractCharacter* character = Cast<ACInteractCharacter>(TargetActor);
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, character->GetName());

		PlayerAdjustment();
		FlashScreen();
		character->ActivateDialogue_Interface();
	}
}

void UCInteractionComponent::AddInteractActor(AActor* InActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "OnBeginOverlap_Interaction");
	InteractionActors.Add(InActor);
}

void UCInteractionComponent::RemoveInteractActor(AActor* InActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, "OnEndOverlap_Interaction");
	if (InteractionActors.Contains(InActor))
	{
		InteractionActors.Remove(InActor);
	}
}

void UCInteractionComponent::PlayerAdjustment()
{
	FInputModeUIOnly inputMode;
	PlayerController->SetInputMode(inputMode);
}

void UCInteractionComponent::FlashScreen()
{
	FTimerHandle timerCameraHandle;
	FTimerHandle timerWidgetHandle;

	BlackScreenWidget->SetVisibility(ESlateVisibility::Visible);
	BlackScreenWidget->PlayAnimFadeInOut();
	GetWorld()->GetTimerManager().SetTimer(timerCameraHandle, this, &UCInteractionComponent::SetCameraMove, 0.2f, false);
	GetWorld()->GetTimerManager().SetTimer(timerWidgetHandle, [&]() { BlackScreenWidget->SetVisibility(ESlateVisibility::Hidden); }, 0.5f, false);
}

void UCInteractionComponent::SetCameraMove()
{
	ACInteractCharacter* interactionCharacter = Cast<ACInteractCharacter>(TargetActor);

	AActor* viewTarget = interactionCharacter->GetSceneCamera()->GetOwner();
	PlayerController->SetViewTargetWithBlend(viewTarget);
	
	FTransform transform;
	float x = interactionCharacter->GetPlayerPosition().X;
	float y = interactionCharacter->GetPlayerPosition().Y;
	float z = PlayerCharacter->GetRootComponent()->GetComponentLocation().Z;
	transform.SetLocation(FVector(x, y, z));

	float roll = PlayerCharacter->GetRootComponent()->GetComponentRotation().Roll;
	float pitch = PlayerCharacter->GetRootComponent()->GetComponentRotation().Pitch;
	float yaw = interactionCharacter->GetMesh()->GetComponentRotation().Yaw - 90.f;
	transform.SetRotation(FQuat(FRotator(pitch, yaw, roll)));

	PlayerCharacter->GetRootComponent()->SetWorldTransform(transform);
}

void UCInteractionComponent::CreateInteractionWidget()
{
	
}

void UCInteractionComponent::SetNearlyActor()
{
	float minDistance = 100000.f;
	AActor* targetActor = nullptr;
	for (const auto actor : InteractionActors)
	{
		float newDistance = PlayerCharacter->GetDistanceTo(actor);
		if (minDistance >= newDistance)
		{
			targetActor = actor;
			minDistance = newDistance;
		}
	}

	TargetActor = targetActor;
}
