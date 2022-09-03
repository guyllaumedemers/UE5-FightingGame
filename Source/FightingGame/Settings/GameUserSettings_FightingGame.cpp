// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUserSettings_FightingGame.h"

//~Static
UGameUserSettings_FightingGame* UGameUserSettings_FightingGame::Singleton = nullptr;
//~Static

UGameUserSettings_FightingGame& UGameUserSettings_FightingGame::Get()
{
	if(!Singleton)
	{
		Singleton = NewObject<UGameUserSettings_FightingGame>();
	}
	return *Singleton;
}

bool UGameUserSettings_FightingGame::Register_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag, const FPlayerMappableInput_Loaded& MappableInput_Loaded)
{
	PlayerMappableInputConfigs_Loaded.Add(GameplayTag, MappableInput_Loaded);
	return true;
}

bool UGameUserSettings_FightingGame::Unregister_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag, const FPlayerMappableInput_Loaded& MappableInput_Loaded)
{
	PlayerMappableInputConfigs_Loaded.Remove(GameplayTag);
	return true;
}

const FPlayerMappableInput_Loaded& UGameUserSettings_FightingGame::Find_PlayerMappableInputLoaded(const FGameplayTag& GameplayTag) const
{
	return *PlayerMappableInputConfigs_Loaded.Find(GameplayTag);
}

/*
 *	Find PlayerMappableConfig_Pair using GameplayTag, retrieve PMI (CommonUI PMI or Fighter PMI)
 *
 */
