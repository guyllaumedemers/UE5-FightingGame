// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedPlayerMappableInput_Pair.h"
#include "GameUserSettings_FightingGame.h"
#include "FightingGame/System/AssetManager_FightingGame.h"

bool FTaggedPlayerMappableInput_Pair::Register(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if(UPlayerMappableInputConfig* PlayerMappableInputConfig = AssetManager->GetAsset(TaggedPlayerMappableInput_Pair.GetPlayerMappableInput()))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		return UserSettings->Register_PlayerMappableInputLoaded(TaggedPlayerMappableInput_Pair.GetGameplayTag(), PlayerMappableInputConfig);
	}
	return false;
}

bool FTaggedPlayerMappableInput_Pair::Unregister(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if (UPlayerMappableInputConfig* PlayerMappableInputConfig = AssetManager->GetAsset(TaggedPlayerMappableInput_Pair.GetPlayerMappableInput()))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		return UserSettings->Unregister_PlayerMappableInputLoaded(TaggedPlayerMappableInput_Pair.GetGameplayTag(), PlayerMappableInputConfig);
	}
	return false;
}

bool FTaggedPlayerMappableInput_Pair::Activate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	return true;
}

bool FTaggedPlayerMappableInput_Pair::Deactivate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	return true;
}
