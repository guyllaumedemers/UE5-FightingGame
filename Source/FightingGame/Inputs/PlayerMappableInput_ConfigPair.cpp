#include "PlayerMappableInput_ConfigPair.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"
#include "FightingGame/System/AssetManager_FightingGame.h"
#include "PlayerMappableInputConfig.h"

void FPlayerMappableInput_PluginConfig::RegisterMappableInputConfig(const FPlayerMappableInput_PluginConfig& InMappableInputConfig)
{
	if (UGameUserSettings_FightingGame* UserSettings = UGameUserSettings_FightingGame::Get())
	{
		UAssetManager_FightingGame& AssetManager = UAssetManager_FightingGame::Get();
		if (const UPlayerMappableInputConfig* LoadedConfig = AssetManager.GetAsset(InMappableInputConfig.Config))
		{
			UserSettings->RegisterPlayerMappableInputConfig(LoadedConfig);
		}
	}
}

void FPlayerMappableInput_PluginConfig::UnRegisterMappableInputConfig(const FPlayerMappableInput_PluginConfig& InMappableInputConfig)
{
	if (UGameUserSettings_FightingGame* UserSettings = UGameUserSettings_FightingGame::Get())
	{
		UAssetManager_FightingGame& AssetManager = UAssetManager_FightingGame::Get();
		if (const UPlayerMappableInputConfig* LoadedConfig = AssetManager.GetAsset(InMappableInputConfig.Config))
		{
			UserSettings->UnRegisterPlayerMappableInputConfigs(LoadedConfig);
		}
	}
}
