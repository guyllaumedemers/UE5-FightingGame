// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TaggedPlayerMappableInput_Pair.h"
#include "FightingGame/Inputs/InputConfig.h"
#include "GameFramework/GameUserSettings.h"
#include "GameUserSettings_FightingGame.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UGameUserSettings_FightingGame : public UGameUserSettings
{
	GENERATED_BODY()

	TMap<FGameplayTag, FPlayerMappableInput_Loaded> PlayerMappableInputConfigs_Loaded;
	TMap<TSubclassOf<APawn>, FInputConfig_Loaded> InputConfig_Loaded;

	static UGameUserSettings_FightingGame* Singleton;

public:

	static UGameUserSettings_FightingGame& Get();

	void Register(const FPlayerMappableInput_Loaded& InPMI, const FGameplayTag& GameplayTag);
	void Register(const FInputConfig_Loaded& InConfig, const TSubclassOf<APawn>& PawnSubClass);
	 
	void Unregister(const FGameplayTag& GameplayTag);
	void Unregister(const TSubclassOf<APawn>& PawnSubClass);

	const FPlayerMappableInput_Loaded& Find(const FGameplayTag& GameplayTag) const;
	const FInputConfig_Loaded& Find(const TSubclassOf<APawn>& PawnSubClass) const;
};
