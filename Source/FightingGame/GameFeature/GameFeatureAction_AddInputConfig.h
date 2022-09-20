// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "GameFeatureAction_AddInputConfig.generated.h"

class UPlayerMappableInputConfig;

USTRUCT()
struct FInputConfig_Register
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UPlayerMappableInputConfig> MappableInputs;

	static void RegisterInUserSettings(const FInputConfig_Register* const InInput);
	static void UnRegisterInUserSettings(const FInputConfig_Register* const InInput);
};

/**
 *	live throughout the session. Register inputs at the lowest level UEnhancedLocalPlayerInputSubsystem
 */
UCLASS()
class FIGHTINGGAME_API UGameFeatureAction_AddInputConfig : public UGameFeatureAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<FInputConfig_Register> MappableConfigs;

public:

	virtual void OnGameFeatureActivating(FGameFeatureActivatingContext& Context) override;
	virtual void OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context) override;
};
