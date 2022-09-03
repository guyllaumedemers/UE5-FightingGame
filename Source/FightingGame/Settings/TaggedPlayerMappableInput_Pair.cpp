// Fill out your copyright notice in the Description page of Project Settings.


#include "TaggedPlayerMappableInput_Pair.h"
#include "GameUserSettings_FightingGame.h"
#include "Engine/AssetManager.h"

bool FTaggedPlayerMappableInput_Pair::Register(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

	check(UserSettings);

	const UPlayerMappableInputConfig* MappableinputConfig_AssetPtr = TaggedPlayerMappableInput_Pair.GetPlayerMappableInput();

	check(MappableinputConfig_AssetPtr);

	if (TSharedPtr<FStreamableHandle> StreamableHandle = UAssetManager::Get().LoadPrimaryAsset(MappableinputConfig_AssetPtr->GetPrimaryAssetId()))
	{
		/*check(StreamableHandle.IsValid());
		UPlayerMappableInputConfig* Streamable_PlayerMappableInputConfig = Cast<UPlayerMappableInputConfig>(StreamableHandle.Get());
		check(Streamable_PlayerMappableInputConfig);
		return UserSettings->Register_PlayerMappableInputLoaded(TaggedPlayerMappableInput_Pair.GetGameplayTag(), FPlayerMappableInput_Loaded(Streamable_PlayerMappableInputConfig));*/
	}
	return false;
}

bool FTaggedPlayerMappableInput_Pair::Unregister(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

	check(UserSettings);

	const UPlayerMappableInputConfig* MappableinputConfig_AssetPtr = TaggedPlayerMappableInput_Pair.GetPlayerMappableInput();

	check(MappableinputConfig_AssetPtr);

	if (TSharedPtr<FStreamableHandle> StreamableHandle = UAssetManager::Get().LoadPrimaryAsset(MappableinputConfig_AssetPtr->GetPrimaryAssetId()))
	{
		/*check(StreamableHandle.IsValid());
		UPlayerMappableInputConfig* Streamable_PlayerMappableInputConfig = Cast<UPlayerMappableInputConfig>(StreamableHandle.Get());
		check(Streamable_PlayerMappableInputConfig);
		return UserSettings->Unregister_PlayerMappableInputLoaded(TaggedPlayerMappableInput_Pair.GetGameplayTag(), FPlayerMappableInput_Loaded(Streamable_PlayerMappableInputConfig));*/
	}
	return false;
}

bool FTaggedPlayerMappableInput_Pair::Activate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	return true;
}

bool FTaggedPlayerMappableInput_Pair::Deactivate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair)
{
	return true;
}
