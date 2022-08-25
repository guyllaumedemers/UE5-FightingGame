#include "MappableConfigPair.h"
#include "FightingGameUserSettings.h"
#include "FightingGame/System/FightingAssetManager.h"
#include "PlayerMappableInputConfig.h"

void FMappableInputConfig::RegisterMappableInputConfig(const FMappableInputConfig& InMappableInputConfig)
{
	if (UFightingGameUserSettings* UserSettings = UFightingGameUserSettings::Get())
	{
		UFightingAssetManager& AssetManager = UFightingAssetManager::Get();
		if(const UPlayerMappableInputConfig* LoadedConfig = AssetManager.GetAsset(InMappableInputConfig.Config))
		{
			//UserSettings->RegisterPlayerMappableInputConfig(LoadedConfig);
		}
	}
}

void FMappableInputConfig::UnRegisterMappableInputConfig(const FMappableInputConfig& InMappableInputConfig)
{
	if (UFightingGameUserSettings* UserSettings = UFightingGameUserSettings::Get())
	{
		UFightingAssetManager& AssetManager = UFightingAssetManager::Get();
		if (const UPlayerMappableInputConfig* LoadedConfig = AssetManager.GetAsset(InMappableInputConfig.Config))
		{
			//UserSettings->UnRegisterPlayerMappableInputConfigs(LoadedConfig);
		}
	}
}
