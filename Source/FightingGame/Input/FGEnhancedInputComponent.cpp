// Fill out your copyright notice in the Description page of Project Settings.


#include "FGEnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"
#include <EnhancedInputSubsystems.h>
#include "Engine/Engine.h"
#include "FightingGame/Settings/FGGameUserSettings.h"

void UFGEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UFGEnhancedInputComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UFGEnhancedInputComponent::RegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer)
{
	if (ensureAlways(InLocalPlayer))
	{
		UEnhancedInputLocalPlayerSubsystem* const LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(InLocalPlayer);
		if (GEngine)
		{
			UFGGameUserSettings* GameUserSettings = Cast<UFGGameUserSettings>(GEngine->GetGameUserSettings());
			if (ensureAlways(GameUserSettings))
			{
				GameUserSettings->RegisterNativeInputConfig(LocalPlayerSubsystem);
			}
		}
	}
}

void UFGEnhancedInputComponent::UnRegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer)
{
	if (ensureAlways(InLocalPlayer))
	{
		UEnhancedInputLocalPlayerSubsystem* const LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(InLocalPlayer);
		if (GEngine)
		{
			UFGGameUserSettings* GameUserSettings = Cast<UFGGameUserSettings>(GEngine->GetGameUserSettings());
			if (ensureAlways(GameUserSettings))
			{
				GameUserSettings->UnRegisterNativeInputConfig(LocalPlayerSubsystem);
			}
		}
	}
}

void UFGEnhancedInputComponent::UnBindNativeAction(const UInputAction* const InInputAction)
{
	if (ensure(InInputAction))
	{
		uint32 InputBindingHandle = EnhancedInputActionEventBindings.FindAndRemoveChecked(InInputAction);

		bool Result =
			RemoveActionEventBinding(InputBindingHandle);

		if (Result)
		{
			UE_LOG(LogTemp, Error, TEXT("Input Binding %s removed"), *InInputAction->GetFName().ToString());
		}
	}
}
