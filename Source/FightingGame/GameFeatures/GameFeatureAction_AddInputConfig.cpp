#include "GameFeatureAction_AddInputConfig.h"

void UGameFeatureAction_AddInputConfig::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureRegistering();
	for (const auto& FMappableInputConfig
		: Configs)
	{
		FMappableInputConfig::RegisterMappableInputConfig(FMappableInputConfig);
	}
}

void UGameFeatureAction_AddInputConfig::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureUnregistering();
	for (const auto& FMappableInputConfig
		: Configs)
	{
		FMappableInputConfig::UnRegisterMappableInputConfig(FMappableInputConfig);
	}
}
