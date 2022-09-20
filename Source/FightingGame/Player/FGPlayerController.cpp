// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerController.h"
#include "FightingGame/Character/ModularPawn.h"
#include "FightingGame/Input/FGEnhancedInputComponent.h"

void AFGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UFGEnhancedInputComponent* const EnhancedComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if(ensureAlways(EnhancedComponent))
	{
		EnhancedComponent->RegisterHardwareInputBindings();
	}
}

void AFGPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AModularPawn* const ModularPawn = Cast<AModularPawn>(InPawn);
	if (ensureAlways(ModularPawn))
	{
		ModularPawn->OnPosses();
	}
}

void AFGPlayerController::OnUnPossess()
{
	AModularPawn* const ModularPawn = Cast<AModularPawn>(GetPawn());
	if (ensureAlways(ModularPawn))
	{
		ModularPawn->OnUnPossess();
	}
	Super::OnUnPossess();
}
