// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddInputActionConfig.generated.h"

class UDataAsset_InputConfig;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UGameFeatureAction_AddInputActionConfig : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (ShortTooltip = "Input Actions - Apawn SetupInputComponent - BindAction"))
	TArray<TSoftObjectPtr<UDataAsset_InputConfig>> InputConfigs;

public:

	UGameFeatureAction_AddInputActionConfig()
	{}

	virtual void OnGameFeatureRegistering() override;
	virtual void OnGameFeatureUnregistering() override;
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
	
};
