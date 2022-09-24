// Fill out your copyright notice in the Description page of Project Settings.


#include "FGGameUserSettings.h"
#include "EnhancedInputSubsystems.h"

void UFGGameUserSettings::BeginDestroy()
{
	SettingHandle_GameCheat.ClearNativeCheatExtensions();
	SettingHandle_GameCheat.ClearWorldCheatExtensions();
	SettingHandle_InputConfig.ClearNativeInputConfig();
	SettingHandle_InputConfig.ClearWorldInputConfig();
	SettingHandle_PawnInputBinding.ClearPawnInputBindings();

	Super::BeginDestroy();
}

void UFGGameUserSettings::RegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const
{
	if(ensureAlways(InLocalPlayerSubsystem))
	{
		for (const auto& InNativeInputPair : SettingHandle_InputConfig.GetNativeInput())
		{
			InLocalPlayerSubsystem->AddPlayerMappableConfig(InNativeInputPair.Value);
		}
	}
}

void UFGGameUserSettings::UnRegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const
{
	if(ensureAlways(InLocalPlayerSubsystem))
	{
		for (const auto& InNativeInputPair : SettingHandle_InputConfig.GetNativeInput())
		{
			InLocalPlayerSubsystem->RemovePlayerMappableConfig(InNativeInputPair.Value);
		}
	}
}