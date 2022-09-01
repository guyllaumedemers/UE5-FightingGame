// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "TaggedInputAction_Pair.generated.h"

/**
 * 
 */
USTRUCT()
struct FTaggedInputAction_Pair
{
	GENERATED_BODY()

	FTaggedInputAction_Pair()
		: InputAction(nullptr)
		, GameplayTag(FGameplayTag())
	{}

	const FGameplayTag& GetGameplayTag() const { return GameplayTag; }
	const UInputAction* GetInputAction() const { return InputAction.Get(); }

	static bool UnRegisterInputAction_Pair(const FTaggedInputAction_Pair& TaggedInputAction_Pair);
	static bool RegisterInputAction_Pair(const FTaggedInputAction_Pair& TaggedInputAction_Pair);

private:

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag;
};

/*
 *	Handles Pairing of Input Action with GameplayTags. Will be used as referenced when Input action are triggered.
 *	Subsystem/or Setting UObject storing this Pair will do Hash comparison on the Input Action fired and process which will run
 *	additional reseach to find abilities triggered by the GameplayTag Paired with the Input Action.
 *
 */
