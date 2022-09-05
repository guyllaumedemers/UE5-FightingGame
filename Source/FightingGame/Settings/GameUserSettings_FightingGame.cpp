// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUserSettings_FightingGame.h"
#include "Engine/Engine.h"
#include "FightingGame/Inputs/InputConfig.h"

//~Static
UGameUserSettings_FightingGame* UGameUserSettings_FightingGame::Singleton = nullptr;
//~Static

UGameUserSettings_FightingGame& UGameUserSettings_FightingGame::Get()
{
	if (!Singleton)
	{
		Singleton = Cast<ThisClass>(GEngine->GameUserSettings.Get());
		if (!Singleton) Singleton = NewObject<ThisClass>();
	}
	return *Singleton;
}

void UGameUserSettings_FightingGame::Register(const FPlayerMappableInput_Loaded& InPMI, const FGameplayTag& GameplayTag)
{
	PlayerMappableInputConfigs_Loaded.Add(GameplayTag, InPMI);
}

void UGameUserSettings_FightingGame::Unregister(const FGameplayTag& GameplayTag)
{
	PlayerMappableInputConfigs_Loaded.Remove(GameplayTag);
}

const FPlayerMappableInput_Loaded& UGameUserSettings_FightingGame::Find(const FGameplayTag& GameplayTag) const
{
	const FPlayerMappableInput_Loaded* OutPMI = PlayerMappableInputConfigs_Loaded.Find(GameplayTag);
	check(OutPMI);
	return *OutPMI;
}

void UGameUserSettings_FightingGame::Register(const FInputConfig_Loaded& InConfig, const TSubclassOf<APawn>& PawnSubClass)
{
	InputConfig_Loaded.Add(PawnSubClass, InConfig);
}

void UGameUserSettings_FightingGame::Unregister(const TSubclassOf<APawn>& PawnSubClass)
{
	InputConfig_Loaded.Remove(PawnSubClass);
}

const FInputConfig_Loaded& UGameUserSettings_FightingGame::Find(const TSubclassOf<APawn>& PawnSubClass) const
{
	const FInputConfig_Loaded* OutInputConfig = InputConfig_Loaded.Find(PawnSubClass);
	check(OutInputConfig);
	return *OutInputConfig;
}
