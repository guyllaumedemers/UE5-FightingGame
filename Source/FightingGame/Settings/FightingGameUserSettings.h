// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MappableConfigPair.h"
#include "GameFramework/GameUserSettings.h"
#include "FightingGameUserSettings.generated.h"

class UPlayerMappableInputConfig;

UCLASS()
class FIGHTINGGAME_API UFightingGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:

	static UFightingGameUserSettings* Get();
	FORCEINLINE TArray<FLoadedMappableInputConfig> GetLoadedMappableInputs() const { return InputConfigs; }

	// lyra have an interesting approach where PMI - adding and removing to the global settings - can be targeted which makes sense
	void RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig*);
	void UnRegisterPlayerMappableInputConfigs(const UPlayerMappableInputConfig*);

private:

	TArray<FLoadedMappableInputConfig> InputConfigs;
};
