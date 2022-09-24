// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerPawn.h"
#include "Engine/Engine.h"
#include "FightingGame/Player/FGComboParserComponent.h"
#include "FightingGame/Player/FGInputBufferComponent.h"
#include "FightingGame/Settings/FGGameUserSettings.h"

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
	if (ensureAlways(EnhancedInputComponent) && ensureAlways(GEngine))
	{
		UFGGameUserSettings* const GameUserSettings = Cast<UFGGameUserSettings>(GEngine->GetGameUserSettings());
		if (ensureAlways(GameUserSettings))
		{
			GameUserSettings->RegisterPawnInputBindings(EnhancedInputComponent, 
				this,
				&ThisClass::OnPlayerInputCaptured);
		}
	}
}

void AFGPlayerPawn::OnUnPossess()
{
	UFGEnhancedInputComponent* const EnhancedInputComponent = Cast<UFGEnhancedInputComponent>(InputComponent);
	if (ensureAlways(EnhancedInputComponent) && ensureAlways(GEngine))
	{
		UFGGameUserSettings* const GameUserSettings = Cast<UFGGameUserSettings>(GEngine->GetGameUserSettings());
		if (ensureAlways(GameUserSettings))
		{
			GameUserSettings->UnRegisterPawnInputBindings(EnhancedInputComponent, this);
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
