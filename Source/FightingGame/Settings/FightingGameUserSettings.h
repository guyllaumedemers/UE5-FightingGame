#pragma once

#include "CoreMinimal.h"
#include "PlayerMappableInputConfig.h"
#include "GameFramework/GameUserSettings.h"
#include "FightingGameUserSettings.generated.h"

class UTaggedInputActionConfig;
class UPlayerMappableInputConfig;

UCLASS()
class FIGHTINGGAME_API UFightingGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:

	static UFightingGameUserSettings* Get();
	const UTaggedInputActionConfig& GetInputConfig() const;
	const TArray<TSoftObjectPtr<UPlayerMappableInputConfig>>& GetPlayerMappableInputConfigs() const;

	// handles caching of PMI - IMC for hardware input mapping
	void RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* LoadedConfig);
	void UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig* LoadedConfig);

private:

	TSoftObjectPtr<UTaggedInputActionConfig> TaggedInputActionConfig;
	TArray<TSoftObjectPtr<UPlayerMappableInputConfig>> PlayerMappableInputConfigs;
};
