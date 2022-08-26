#pragma once

#include "CoreMinimal.h"
#include "PlayerMappableInputConfig.h"
#include "GameFramework/GameUserSettings.h"
#include "GameUserSettings_FightingGame.generated.h"

class UTaggedInputAction_Config;
class UPlayerMappableInputConfig;

UCLASS()
class FIGHTINGGAME_API UGameUserSettings_FightingGame : public UGameUserSettings
{
	GENERATED_BODY()

public:

	static UGameUserSettings_FightingGame* Get();
	const UTaggedInputAction_Config& GetInputConfig() const;
	const TArray<TSoftObjectPtr<UPlayerMappableInputConfig>>& GetPlayerMappableInputConfigs() const;

	// handles caching of PMI - IMC for hardware input mapping
	void RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* LoadedConfig);
	void UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig* LoadedConfig);

private:

	TSoftObjectPtr<UTaggedInputAction_Config> TaggedInputActionConfig;
	TArray<TSoftObjectPtr<UPlayerMappableInputConfig>> PlayerMappableInputConfigs;
};
