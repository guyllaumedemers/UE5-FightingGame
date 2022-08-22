#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FightingGame/Settings/MappableConfigPair.h"
#include "GameFeatureAction_AddInputConfig.generated.h"

UCLASS(meta = (DisplayName = "Add Input Config"))
class FIGHTINGGAME_API UGameFeatureAction_AddInputConfig : public UGameFeatureAction
{
	GENERATED_BODY()

public:

	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;

private:

	UPROPERTY(EditAnywhere)
	TArray<FMappableInputConfig> Configs;
};
