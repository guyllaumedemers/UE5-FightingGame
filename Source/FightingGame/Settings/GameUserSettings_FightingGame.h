#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "PlayerMappableInputConfig.h"
#include "FightingGame/Inputs/TaggedInputAction_Config.h"
#include "GameUserSettings_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameUserSettings_FightingGame : public UGameUserSettings
{
	GENERATED_BODY()

	TSoftObjectPtr<UTaggedInputAction_Config> TaggedInputActionConfig;
	TArray<TSoftObjectPtr<UPlayerMappableInputConfig>> PlayerMappableInputConfigs;

protected:

	UGameUserSettings_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};

public:

	static UGameUserSettings_FightingGame* Get();

	// handles caching of PMI - IMC for hardware input mapping
	void RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* LoadedConfig);
	void UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig* LoadedConfig);

	const UTaggedInputAction_Config& GetInputConfig() const;
	const TArray<TSoftObjectPtr<UPlayerMappableInputConfig>>& GetPlayerMappableInputConfigs() const;
};
