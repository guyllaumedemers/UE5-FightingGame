#include "GameFeatureAction_AddInputConfig.h"
#include "PlayerMappableInputConfig.h"
#include "../Settings/MappableConfigPair.h"
#include "../Settings/FightingGameUserSettings.h"
#include "Engine/Engine.h"
#include "FightingGame/System/FightingAssetManager.h"

void UGameFeatureAction_AddInputConfig::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureRegistering();

	UFightingAssetManager& AssetManager = UFightingAssetManager::Get();

	if (UFightingGameUserSettings* UserSettings = UFightingGameUserSettings::Get())
	{
		for (const auto& it
			: Configs)
		{
			UserSettings->RegisterPlayerMappableInputConfig(AssetManager.GetAsset(it.Config));
		}
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("OnGameFeatureAction_AddInput_Registering"));
		}
	}
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureUnregistering();

	UFightingAssetManager& AssetManager = UFightingAssetManager::Get();

	if (UFightingGameUserSettings* UserSettings = UFightingGameUserSettings::Get())
	{
		for (const auto& it
			: Configs)
		{
			UserSettings->UnRegisterPlayerMappableInputConfigs(AssetManager.GetAsset(it.Config));
		}
	}
}
