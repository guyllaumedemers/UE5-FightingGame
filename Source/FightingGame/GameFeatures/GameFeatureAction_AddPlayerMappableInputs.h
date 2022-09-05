// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FightingGame/Settings/TaggedPlayerMappableInput_Pair.h"
#include "GameFeatureAction_AddPlayerMappableInputs.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "Add Player Mappable Inputs"))
class FIGHTINGGAME_API UGameFeatureAction_AddPlayerMappableInputs : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (DisplayName = "Mappable Input List"))
	TArray<FTaggedPlayerMappableInput_Pair> MappableInputs_Pairs;

public:

	UGameFeatureAction_AddPlayerMappableInputs()
	{}

	virtual void OnGameFeatureRegistering() override;
	virtual void OnGameFeatureUnregistering() override;
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
