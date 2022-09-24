// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FightingGame/Input/FGEnhancedInputComponent.h"
#include "GameFramework/CheatManager.h"
#include "GameFramework/GameUserSettings.h"
#include "GameFramework/Pawn.h"
#include "FGGameUserSettings.generated.h"

class UPlayerMappableInputConfig;

struct FInputSettingHandle
{
	FInputSettingHandle()
		: Inputs_Static(TMap<FGameplayTag, const UPlayerMappableInputConfig*>())
		, Inputs_Dynamic(TMap<FGameplayTag, const UPlayerMappableInputConfig*>())
	{}

	~FInputSettingHandle()
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

	FORCEINLINE const UPlayerMappableInputConfig* FindNativeInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
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

	FORCEINLINE const UPlayerMappableInputConfig* FindWorldInputConfig(const FGameplayTag& InPlayerMappable_GameplayTag)
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

	const TMap<FGameplayTag, const UPlayerMappableInputConfig*>& GetNativeInput() const { return Inputs_Static; }
	const TMap<FGameplayTag, const UPlayerMappableInputConfig*>& GetWorldInput() const { return Inputs_Dynamic; }

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

	~FGameModeSettingHandle()
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

class UFGPawnInputConfig;

struct FPawnBindingSettingHandle
{
	FPawnBindingSettingHandle()
		: PawnInputBindings(TMap<TSubclassOf<APawn>, const UFGPawnInputConfig*>())
	{}

	~FPawnBindingSettingHandle()
	{}

	FORCEINLINE void AddPawnInputBindings(TSubclassOf<APawn> InPawn, const UFGPawnInputConfig* const InPawnBindings)
	{
		PawnInputBindings.FindOrAdd(InPawn, InPawnBindings);
	}

	FORCEINLINE void RemovePawnInputBindings(TSubclassOf<APawn> InPawn)
	{
		PawnInputBindings.FindAndRemoveChecked(InPawn);
	}

	FORCEINLINE const UFGPawnInputConfig* FindPawnInputBindings(TSubclassOf<APawn> InPawn)
	{
		const UFGPawnInputConfig** OutHandle = PawnInputBindings.Find(InPawn);
		if (OutHandle)
		{
			return *OutHandle;
		}
		UE_LOG(LogTemp, Error, TEXT("%s Invalid."), *(InPawn->GetFName().ToString()));
		return nullptr;
	}

	FORCEINLINE void ClearPawnInputBindings()
	{
		PawnInputBindings.Empty();
	}

	const TMap<TSubclassOf<APawn>, const UFGPawnInputConfig*>& GetPawnBindings() const { return PawnInputBindings; }

private:

	TMap<TSubclassOf<APawn>, const UFGPawnInputConfig*> PawnInputBindings;
};

class UEnhancedInputLocalPlayerSubsystem;
struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

	FGameModeSettingHandle GameModeSettingHandle; /*Should make sure that AGameModeBase::AllowCheats true in practice mode*/
	FInputSettingHandle InputSettingHandle;
	FPawnBindingSettingHandle PawnBindingSettingHandle;

public:

	virtual void BeginDestroy() override;

public:

	void RegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const;
	void UnRegisterNativeInputConfig(UEnhancedInputLocalPlayerSubsystem* const InLocalPlayerSubsystem) const;

	template<typename UserClass, typename FncPtr>
	void RegisterPawnInputBindings(UFGEnhancedInputComponent* const InEnhancedInputComponent, UserClass* InUser, FncPtr InFncPtr);
	template<typename UserClass>
	void UnRegisterPawnInputBindings(UFGEnhancedInputComponent* const InEnhancedInputComponent, UserClass* InUser);
};

template <typename UserClass, typename FncPtr>
void UFGGameUserSettings::RegisterPawnInputBindings(UFGEnhancedInputComponent* const InEnhancedInputComponent,
	UserClass* InUser, FncPtr InFncPtr)
{
	if (ensureAlways(InEnhancedInputComponent) && ensureAlways(InUser))
	{
		const UFGPawnInputConfig* const PawnInputBindings = PawnBindingSettingHandle.FindPawnInputBindings(TSubclassOf<APawn>(Cast<APawn>(InUser)->GetClass())); /*Unsafe ptr access*/
		if (ensure(PawnInputBindings))
		{
			for (const auto& InPair : PawnInputBindings->GetInputBindingPairs())
			{
				InEnhancedInputComponent->BindNativeAction(PawnInputBindings,
					InPair.GameplayTag_InputAction_Registered,
					ETriggerEvent::Started,
					InUser,
					InFncPtr);
			}
		}
	}
}

template <typename UserClass>
void UFGGameUserSettings::UnRegisterPawnInputBindings(UFGEnhancedInputComponent* const InEnhancedInputComponent,
	UserClass* InUser)
{
	if (ensureAlways(InEnhancedInputComponent) && ensureAlways(InUser))
	{
		const UFGPawnInputConfig* const PawnInputBindings = PawnBindingSettingHandle.FindPawnInputBindings(TSubclassOf<APawn>(Cast<APawn>(InUser)->GetClass()));
		if (ensure(PawnInputBindings))
		{
			for (const auto& InActionBinding_Pair : PawnInputBindings->GetInputBindingPairs())
			{
				InEnhancedInputComponent->UnBindNativeAction(InActionBinding_Pair.InputAction_Registered.Get());
			}
		}
	}
}
