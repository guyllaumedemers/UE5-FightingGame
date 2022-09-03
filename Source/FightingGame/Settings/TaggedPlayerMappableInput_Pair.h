// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PlayerMappableInputConfig.h"
#include "TaggedPlayerMappableInput_Pair.generated.h"

struct FPlayerMappableInput_Loaded
{
	FPlayerMappableInput_Loaded(const UPlayerMappableInputConfig* MappableInputConfig, bool bIsActive = false)
		: PlayerMappableInput(MappableInputConfig)
		, bIsActive(bIsActive)
	{}

	FPlayerMappableInput_Loaded()
		: PlayerMappableInput(nullptr)
		, bIsActive(false)
	{}

	const UPlayerMappableInputConfig* GetPlayerMappableInput() const { return PlayerMappableInput; }
	const bool& IsActive() const { return bIsActive; }
	void SetIsActive(const bool& IsActive) { bIsActive = IsActive; }

private:

	const UPlayerMappableInputConfig* PlayerMappableInput;
	bool bIsActive;
};

/**
 * 
 */
USTRUCT()
struct FTaggedPlayerMappableInput_Pair
{
	GENERATED_BODY()

	FTaggedPlayerMappableInput_Pair()
		: PlayerMappableInput(nullptr)
		, GameplayTag(FGameplayTag())
		, bShouldActivateAutomatically(false)
	{}

	TSoftObjectPtr<UPlayerMappableInputConfig> GetPlayerMappableInput() const { return PlayerMappableInput; }
	const FGameplayTag& GetGameplayTag() const { return GameplayTag; }
	bool ShouldActivateAutomatically() const { return bShouldActivateAutomatically; }

	static bool Register(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair);
	static bool Unregister(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair);
	static bool Activate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair);
	static bool Deactivate(const FTaggedPlayerMappableInput_Pair& TaggedPlayerMappableInput_Pair);

private:

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UPlayerMappableInputConfig> PlayerMappableInput;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly)
	bool bShouldActivateAutomatically;
};

/*
 *	Handles hardware inputs mapping with Input Action. Tags are used for plateform filtering - Fighter, UI.
 *	To be registered with the UEnhancedLocalPlayerInputSubsystem.
 *
 */