// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/CheatManager.h"
#include "GameFramework/GameUserSettings.h"
#include "FGGameUserSettings.generated.h"

class UPlayerMappableInputConfig;

struct FInputSettingHandle
{
	FInputSettingHandle()
		: Inputs_Static(TMap<FGameplayTag, const UPlayerMappableInputConfig*>())
		, Inputs_Dynamic(TMap<FGameplayTag, const UPlayerMappableInputConfig*>())
	{}

	FORCEINLINE void AddNativeInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag
		, const UPlayerMappableInputConfig* const InPlayerMappableInputConfig)
	{
		Inputs_Static.FindOrAdd(InPlayerMappable_GameplayTag, InPlayerMappableInputConfig);
	}

	FORCEINLINE void RemoveNativeInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
	{
		Inputs_Static.FindAndRemoveChecked(InPlayerMappable_GameplayTag);
	}

	FORCEINLINE const UPlayerMappableInputConfig* GetNativeInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
	{
		const UPlayerMappableInputConfig** OutHandle = Inputs_Static.Find(InPlayerMappable_GameplayTag);
		if(OutHandle)
		{
			return *OutHandle;
		}
		UE_LOG(LogTemp, Error, TEXT("%s Invalid."), *InPlayerMappable_GameplayTag.ToString());
		return nullptr;
	}

	FORCEINLINE void AddWorldInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag
		, const UPlayerMappableInputConfig* const InPlayerMappableInputConfig)
	{
		Inputs_Dynamic.FindOrAdd(InPlayerMappable_GameplayTag, InPlayerMappableInputConfig);
	}

	FORCEINLINE void RemoveWorldInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
	{
		Inputs_Dynamic.FindAndRemoveChecked(InPlayerMappable_GameplayTag);
	}

	FORCEINLINE const UPlayerMappableInputConfig* GetWorldInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
	{
		const UPlayerMappableInputConfig** OutHandle = Inputs_Dynamic.Find(InPlayerMappable_GameplayTag);
		if (OutHandle)
		{
			return *OutHandle;
		}
		UE_LOG(LogTemp, Error, TEXT("%s Invalid."), *InPlayerMappable_GameplayTag.ToString());
		return nullptr;
	}

	FORCEINLINE void ClearNativeInputConfig()
	{
		Inputs_Static.Empty();
	}

	FORCEINLINE void ClearWorldInputConfig()
	{
		Inputs_Dynamic.Empty();
	}

private:
	
	TMap<FGameplayTag, const UPlayerMappableInputConfig*> Inputs_Static; /*System Inputs*/
	TMap<FGameplayTag, const UPlayerMappableInputConfig*> Inputs_Dynamic; /*Gameplay Inputs - UWorld Specific*/
};

struct FGameModeSettingHandle
{
	/**
	 *	Game Mode Sets base logic like which pawn to load, playercontroller, etc... but doesnt allow Runtime customization via UserSettings of Gameplay Cheats.
	 *	this handle would store Cheats available per Game Mode - loaded via GameFeature Actions. A player in practice mode would be able to have in its UI Cheats to enable/disable
	 *	
	 *	TODO Research Cheat Creation - https://benui.ca/unreal/cheatmanager/#:~:text=Unreal%20Engine%20has%20a%20built,%60%20and%20~%20on%20it).
	 */

	/**
	 *	UI System will load the list of Cheat Extension available per GameMode Experience
	 *	OnStateChange will send a copy of the extension to the playercontroller listening for the event and trigger its own callback
	 *
	 */

	FGameModeSettingHandle()
		: Cheats_Static(TMap<FGameplayTag, const UCheatManagerExtension*>())
		, Cheats_Dynamic(TMap<FGameplayTag, const UCheatManagerExtension*>())
	{}

	FORCEINLINE void AddNativeCheatExtension(const FGameplayTag & InCheatExtension_GameplayTag
		, const UCheatManagerExtension* const InCheatExtension)
	{
		Cheats_Static.FindOrAdd(InCheatExtension_GameplayTag, InCheatExtension);
	}

	FORCEINLINE void RemoveNativeCheatExtension(const FGameplayTag & InCheatExtension_GameplayTag)
	{
		Cheats_Static.FindAndRemoveChecked(InCheatExtension_GameplayTag);
	}

	FORCEINLINE const UCheatManagerExtension* FindNativeCheatExtension(const FGameplayTag & InCheatExtension_GameplayTag)
	{
		const UCheatManagerExtension** OutHandle = Cheats_Static.Find(InCheatExtension_GameplayTag);
		if (OutHandle)
		{
			return *OutHandle;
		}
		UE_LOG(LogTemp, Error, TEXT("%s Invalid."), *InCheatExtension_GameplayTag.ToString());
		return nullptr;
	}

	FORCEINLINE void AddWorldCheatExtension(const FGameplayTag& InCheatExtension_GameplayTag
		, const UCheatManagerExtension* const InCheatExtension)
	{
		Cheats_Dynamic.FindOrAdd(InCheatExtension_GameplayTag, InCheatExtension);
	}

	FORCEINLINE void RemoveWorldCheatExtension(const FGameplayTag& InCheatExtension_GameplayTag)
	{
		Cheats_Dynamic.FindAndRemoveChecked(InCheatExtension_GameplayTag);
	}

	FORCEINLINE const UCheatManagerExtension* FindWorldCheatExtension(const FGameplayTag& InCheatExtension_GameplayTag)
	{
		const UCheatManagerExtension** OutHandle = Cheats_Dynamic.Find(InCheatExtension_GameplayTag);
		if (OutHandle)
		{
			return *OutHandle;
		}
		UE_LOG(LogTemp, Error, TEXT("%s Invalid."), *InCheatExtension_GameplayTag.ToString());
		return nullptr;
	}

	FORCEINLINE void ClearNativeCheatExtensions()
	{
		Cheats_Static.Empty();
	}

	FORCEINLINE void ClearWorldCheatExtensions()
	{
		Cheats_Dynamic.Empty();
	}

private:

	TMap<FGameplayTag, const UCheatManagerExtension*> Cheats_Static; /*System Cheats*/
	TMap<FGameplayTag, const UCheatManagerExtension*> Cheats_Dynamic; /*Gameplay Cheats - UWorld Specific*/
};

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

	FGameModeSettingHandle GameModeSettingHandle; /*Should make sure that AGameModeBase::AllowCheats true in practice mode*/
	FInputSettingHandle InputSettingHandle;

public:

	virtual void BeginDestroy() override;
};
