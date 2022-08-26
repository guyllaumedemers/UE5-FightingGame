#include "GameUserSettings_FightingGame.h"
#include "Engine/Engine.h"
#include "FightingGame/Inputs/TaggedInputAction_Config.h"

UGameUserSettings_FightingGame* UGameUserSettings_FightingGame::Get()
{
	// make sure to update project settings BEFORE running a CastChecked -- otherwise c++ code will compile but not link properly with GEngine pointing to the base class 
	return GEngine ? CastChecked<ThisClass>(GEngine->GetGameUserSettings()) : nullptr;
}

const UTaggedInputAction_Config& UGameUserSettings_FightingGame::GetInputConfig() const
{
	return *TaggedInputActionConfig.Get();
}

const TArray<TSoftObjectPtr<UPlayerMappableInputConfig>>& UGameUserSettings_FightingGame::GetPlayerMappableInputConfigs() const
{
	return PlayerMappableInputConfigs;
}

void UGameUserSettings_FightingGame::RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* LoadedConfig)
{
	check(LoadedConfig);
	PlayerMappableInputConfigs.AddUnique(LoadedConfig);
}

void UGameUserSettings_FightingGame::UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig* LoadedConfig)
{
	check(LoadedConfig);
	PlayerMappableInputConfigs.Remove(LoadedConfig);
}
