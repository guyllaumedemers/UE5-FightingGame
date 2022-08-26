#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FightingGame/Settings/PlayerMappableInput_ConfigPair.h"
#include "GameFeatureAction_AddInputConfig.generated.h"

UCLASS(meta = (DisplayName = "Add Input Config"))
class FIGHTINGGAME_API UGameFeatureAction_AddInputConfig : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FPlayerMappableInput_PluginConfig> PlayerMappableInput_PluginConfigs;

public:

	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
