// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedPlayerMappableInput_Pair.h"
#include "GameUserSettings_FightingGame.h"
#include "PlayerMappableInputConfig.h"
#include "FightingGame/System/AssetManager_FightingGame.h"

void FTaggedPlayerMappableInput_Pair::Register(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if(const UPlayerMappableInputConfig* PlayerMappableInputConfig = AssetManager->GetAsset(TaggedPlayerMappableInput_Pair.GetPlayerMappableInput()))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		UserSettings->Register(PlayerMappableInputConfig, TaggedPlayerMappableInput_Pair.GetGameplayTag());
	}
}

void FTaggedPlayerMappableInput_Pair::Unregister(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if (const UPlayerMappableInputConfig* PlayerMappableInputConfig = AssetManager->GetAsset(TaggedPlayerMappableInput_Pair.GetPlayerMappableInput()))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		UserSettings->Unregister(TaggedPlayerMappableInput_Pair.GetGameplayTag());
	}
}

void FTaggedPlayerMappableInput_Pair::Activate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
}

void FTaggedPlayerMappableInput_Pair::Deactivate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
}
