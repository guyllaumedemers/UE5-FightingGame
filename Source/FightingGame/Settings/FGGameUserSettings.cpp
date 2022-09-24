// Fill out your copyright notice in the Description page of Project Settings.


#include "FGGameUserSettings.h"
#include "EnhancedInputSubsystems.h"

void UFGGameUserSettings::BeginDestroy()
{
	GameModeSettingHandle.ClearNativeCheatExtensions();
	GameModeSettingHandle.ClearWorldCheatExtensions();
	InputSettingHandle.ClearNativeInputConfig();
	InputSettingHandle.ClearWorldInputConfig();
	PawnBindingSettingHandle.ClearPawnInputBindings();

	Super::BeginDestroy();
}

void UFGGameUserSettings::RegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const
{
	if(ensureAlways(InLocalPlayerSubsystem))
	{
		for (const auto& InPair : InputSettingHandle.GetNativeInput())
		{
			InLocalPlayerSubsystem->AddPlayerMappableConfig(InPair.Value);
		}
	}
}

void UFGGameUserSettings::UnRegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const
{
	if(ensureAlways(InLocalPlayerSubsystem))
	{
		for (const auto& InPair : InputSettingHandle.GetNativeInput())
		{
			InLocalPlayerSubsystem->RemovePlayerMappableConfig(InPair.Value);
		}
	}
}