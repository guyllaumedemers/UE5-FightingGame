#include "FightingGameUserSettings.h"
#include "Engine/Engine.h"
#include "MappableConfigPair.h"
#include "PlayerMappableInputConfig.h"

UFightingGameUserSettings* UFightingGameUserSettings::Get()
{
	// make sure to update project settings BEFORE running a CastChecked -- otherwise c++ code will compile but not link properly with GEngine pointing to the base class 
	return GEngine ? CastChecked<ThisClass>(GEngine->GetGameUserSettings()) : nullptr;
}

void UFightingGameUserSettings::RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* NewEntry)
{
	if (NewEntry)
	{
		uint8 ExistingConfigIndex = InputConfigs.IndexOfByPredicate([&](const FLoadedMappableInputConfig& MIE)
			{ return MIE.Config == NewEntry; });
		if (ExistingConfigIndex != INDEX_NONE)
		{
			const auto NumAdded = InputConfigs.Add(FLoadedMappableInputConfig(NewEntry));
			// lyra broadcast the registered entry but irreleveant for me now.
		}
	}
}

void UFightingGameUserSettings::UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig* RemoveEntry)
{
	if (RemoveEntry)
	{
		uint8 ExistingConfigIndex = InputConfigs.IndexOfByPredicate([&](const FLoadedMappableInputConfig& MIE)
			{ return MIE.Config == RemoveEntry; });
		if (ExistingConfigIndex != INDEX_NONE)
		{
			InputConfigs.RemoveAt(ExistingConfigIndex);
			// lyra broadcast the registered entry but irreleveant for me now.
		}
	}
}
