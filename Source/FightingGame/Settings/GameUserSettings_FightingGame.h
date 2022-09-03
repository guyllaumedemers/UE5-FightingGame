// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TaggedPlayerMappableInput_Pair.h"
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
	static UGameUserSettings_FightingGame* Singleton;

public:

	UGameUserSettings_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};

	static UGameUserSettings_FightingGame& Get();
	bool Register_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag, const FPlayerMappableInput_Loaded& MappableInput_Loaded);
	bool Unregister_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag, const FPlayerMappableInput_Loaded& MappableInput_Loaded);
	const FPlayerMappableInput_Loaded& Find_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag) const;
};
