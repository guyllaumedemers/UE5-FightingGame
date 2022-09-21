// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerController.h"
#include "FightingGame/Character/ModularPawn.h"
#include "FightingGame/Input/FGEnhancedInputComponent.h"

void AFGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AFGPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UFGEnhancedInputComponent* const EnhancedComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if (ensureAlways(EnhancedComponent))
	{
		EnhancedComponent->UnRegisterHardwareInputBindings(GetLocalPlayer() /*Should unregister native inputs*/);
	}

	Super::EndPlay(EndPlayReason);
}

void AFGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UFGEnhancedInputComponent* const EnhancedComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if(ensureAlways(EnhancedComponent))
	{
		EnhancedComponent->RegisterHardwareInputBindings(GetLocalPlayer() /*Should register native inputs*/);
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
