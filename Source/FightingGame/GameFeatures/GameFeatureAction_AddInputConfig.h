// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddInputConfig.generated.h"

class UInputConfig;

/**
 * 
 */
UCLASS(meta = (DisplayName = "Add Input Config", ScriptName="Input Config"))
class FIGHTINGGAME_API UGameFeatureAction_AddInputConfig : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Input Config List"))
	TArray<TSoftObjectPtr<UInputConfig>> InputConfigs;

public:

	UGameFeatureAction_AddInputConfig()
	{}

	virtual void OnGameFeatureRegistering() override;
	virtual void OnGameFeatureUnregistering() override;
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
