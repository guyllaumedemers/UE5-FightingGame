// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureAction_AddInputConfig.h"
#include "FightingGame/Inputs/InputConfig.h"

void UGameFeatureAction_AddInputConfig::OnGameFeatureRegistering()
{
	Super::OnGameFeatureRegistering();
	//for (const auto& Config : InputConfigs) UInputConfig::Register(Config);
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureUnregistering()
{
	Super::OnGameFeatureUnregistering();
	//for (const auto& Config : InputConfigs) UInputConfig::Unregister(Config);
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	for (const auto& Config : InputConfigs) UInputConfig::Register(Config);
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	for (const auto& Config : InputConfigs) UInputConfig::Unregister(Config);
}
