// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include <InputMappingContext.h>
#include "GameFeatureAction_AddInputs.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UGameFeatureAction_AddInputs : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta=(ShortTooltip="Input Mappings - UEnhancedLocalPlayerInputSubsystem"))
	TArray<TSoftObjectPtr<UInputMappingContext>> InputMappings;

public:

	UGameFeatureAction_AddInputs()
	{}

	//~GameFeature_Action INTERFACE
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	//~GameFeature_Action INTERFACE
};
