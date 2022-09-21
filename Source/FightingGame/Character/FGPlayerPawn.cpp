// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerPawn.h"
#include "FightingGame/Input/FGEnhancedInputComponent.h"
#include "FightingGame/Input/FGInputActionPair.h"
#include "FightingGame/Player/FGComboParserComponent.h"
#include "FightingGame/Player/FGInputBufferComponent.h"

AFGPlayerPawn::AFGPlayerPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	InputBufferComponent = CreateDefaultSubobject<UFGInputBufferComponent>(UFGInputBufferComponent::StaticClass()->GetFName());
	ComboParserComponent = CreateDefaultSubobject<UFGComboParserComponent>(UFGComboParserComponent::StaticClass()->GetFName());;
}

void AFGPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AFGPlayerPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AFGPlayerPawn::OnPosses()
{
	Super::OnPosses();

	UFGEnhancedInputComponent* const EnhancedInputComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if (ensureAlways(EnhancedInputComponent))
	{
		const FGPawnInputConfig_Loaded* const PawnInputConfig_Loaded = nullptr; /*Retrieve from Settings?*/
		if (ensure(PawnInputConfig_Loaded))
		{
			for (const auto& ActionListener : PawnInputConfig_Loaded->PawnInputConfig->GetInputPairs())
			{
				EnhancedInputComponent->BindNativeAction(PawnInputConfig_Loaded->PawnInputConfig, ActionListener.GameplayTag_InputAction_Registered, ETriggerEvent::Started, this, &ThisClass::OnPlayerInputCaptured);
			}
		}
	}
}

void AFGPlayerPawn::OnUnPossess()
{
	UFGEnhancedInputComponent* const EnhancedInputComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if (ensureAlways(EnhancedInputComponent))
	{
		const FGPawnInputConfig_Loaded* const PawnInputConfig_Loaded = nullptr; /*Retrieve from Settings?*/
		if (ensure(PawnInputConfig_Loaded))
		{
			for (const auto& ActionListener : PawnInputConfig_Loaded->PawnInputConfig->GetInputPairs())
			{
				EnhancedInputComponent->UnBindNativeAction(ActionListener.InputAction_Registered.Get());
			}
		}
	}

	Super::OnUnPossess();
}

void AFGPlayerPawn::OnPlayerInputCaptured(const FInputActionInstance& InputActionInstance)
{
	if (ensureAlways(InputBufferComponent))
	{
		InputBufferComponent->Add(InputActionInstance.GetSourceAction());
	}
}
