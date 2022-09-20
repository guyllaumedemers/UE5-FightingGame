// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureAction_AddInputConfig.h"

void FInputConfig_Register::RegisterInUserSettings(const FInputConfig_Register* const InInput)
{
}

void FInputConfig_Register::UnRegisterInUserSettings(const FInputConfig_Register* const InInput)
{
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	for(const auto& InConfig : MappableConfigs)
	{
		FInputConfig_Register::RegisterInUserSettings(&InConfig);
	}
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	for (const auto& InConfig : MappableConfigs)
	{
		FInputConfig_Register::UnRegisterInUserSettings(&InConfig);
	}
}
