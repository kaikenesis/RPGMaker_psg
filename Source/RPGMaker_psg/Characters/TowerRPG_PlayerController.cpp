#include "Characters/TowerRPG_PlayerController.h"

ATowerRPG_PlayerController::ATowerRPG_PlayerController()
{
	
}

void ATowerRPG_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	Init();
}

void ATowerRPG_PlayerController::Init()
{
	SetInputModeGameOnly();
}

void ATowerRPG_PlayerController::SetInputModeUIOnly()
{
	FInputModeUIOnly inputMode;
	SetInputMode(inputMode);
}

void ATowerRPG_PlayerController::SetInputModeGameOnly()
{
	FInputModeGameOnly inputMode;
	SetInputMode(inputMode);
}
