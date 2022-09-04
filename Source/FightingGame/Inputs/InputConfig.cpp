// Fill out your copyright notice in the Description page of Project Settings.


#include "InputConfig.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"
#include "FightingGame/System/AssetManager_FightingGame.h"

const UInputAction* UInputConfig::FindInputActionByTag(const FGameplayTag& GameplayTag) const
{
	uint16 Index = InputAction_Pairs.IndexOfByPredicate([&](const FTaggedInputAction_Pair& Entry_Pair) { return Entry_Pair.GetGameplayTag() == GameplayTag; });
	return Index != INDEX_NONE ? InputAction_Pairs[Index].GetInputAction() : nullptr;
}

void UInputConfig::Register(const TSoftObjectPtr<UInputConfig>& InputConfig)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if (const UInputConfig* InputConfig_Loaded = AssetManager->GetAsset(InputConfig))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		UserSettings->Register(FInputConfig_Loaded(InputConfig_Loaded), InputConfig->PawnSubClass);
	}
}

void UInputConfig::Unregister(const TSoftObjectPtr<UInputConfig>& InputConfig)
{
	UAssetManager_FightingGame* AssetManager = &UAssetManager_FightingGame::Get();

	check(AssetManager);

	if (const UInputConfig* InputConfig_Loaded = AssetManager->GetAsset(InputConfig))
	{
		UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		UserSettings->Unregister(InputConfig->PawnSubClass);
	}
}

void UInputConfig::Activate(const TSoftObjectPtr<UInputConfig>& InputConfig)
{
}

void UInputConfig::Deactivate(const TSoftObjectPtr<UInputConfig>& InputConfig)
{
}
