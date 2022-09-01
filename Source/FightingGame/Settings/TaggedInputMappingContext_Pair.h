// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputMappingContext.h"
#include "TaggedInputMappingContext_Pair.generated.h"

/**
 * 
 */
USTRUCT()
struct FTaggedInputMappingContext_Pair
{
	GENERATED_BODY()

	FTaggedInputMappingContext_Pair()
		: InputMappingContext(nullptr)
		, GameplayTag(FGameplayTag())
	{}

	const FGameplayTag& GetGameplayTag() const { return GameplayTag; }
	const UInputMappingContext* GetInputMappingContext() const { return InputMappingContext.Get(); }

	static bool UnRegisterInputMappingContext_Pair(const FTaggedInputMappingContext_Pair& TaggedInputMappingContext_Pair);
	static bool RegisterInputMappingContext_Pair(const FTaggedInputMappingContext_Pair& TaggedInputMappingContext_Pair);

private:

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag;
};

/*
 *	Handles hardware inputs mapping with Input Action. Tags are used for plateform filtering - Fighter, UI.
 *	To be registered with the UEnhancedLocalPlayerInputSubsystem.
 *
 */