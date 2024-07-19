#include "Components/CActionComponent.h"

UCActionComponent::UCActionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UCActionComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

