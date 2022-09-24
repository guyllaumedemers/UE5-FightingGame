// Fill out your copyright notice in the Description page of Project Settings.


#include "FGGameUserSettings.h"

void UFGGameUserSettings::BeginDestroy()
{
	GameModeSettingHandle.ClearNativeCheatExtensions();
	GameModeSettingHandle.ClearWorldCheatExtensions();
	InputSettingHandle.ClearNativeInputConfig();
	InputSettingHandle.ClearWorldInputConfig();

	Super::BeginDestroy();
}
