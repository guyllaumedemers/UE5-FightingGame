// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingPlayerController.h"
#include "FightingCharacterBase.h"
#include "InputBufferComponent.h"

AFightingPlayerController::AFightingPlayerController(const FObjectInitializer& FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	OnPossessedPawnChanged.AddDynamic(this, &AFightingPlayerController::BindPlayerControllerInputs);
}

void AFightingPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AFightingPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AFightingPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

/*
 * AcknowledgedPawn is used in net -> might not be the proper information needed.
 * Pc looks for the APawn controlled to bind inputs in regard to the APawn configuration.
 *
 *		Character_A: Jab, Press X
 *		Character_B: Jab, Press Y
 *
 *	Both can have various inputs that change according to their setup. This add a layer of complexity to input learning
 *	and create variation. See, Tekken7 for reference.
 */
void AFightingPlayerController::BindPlayerControllerInputs(APawn* OldPawnControlled, APawn* NewPawnControlled)
{
	const AFightingCharacterBase* NewBaseCharacter = Cast<AFightingCharacterBase>(NewPawnControlled);
	if(NewBaseCharacter)
	{
		UInputBufferComponent* BaseCharacterInputBufferComponent = NewBaseCharacter->GetInputBufferComponent();
		if(BaseCharacterInputBufferComponent)
		{
			InputComponent->ClearActionBindings();
			InputComponent->BindAction("RegisterInput", EInputEvent::IE_Pressed, BaseCharacterInputBufferComponent, &UInputBufferComponent::CaptureInput);
		}
	}
}