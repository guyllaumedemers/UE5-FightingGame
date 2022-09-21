// Fill out your copyright notice in the Description page of Project Settings.


#include "FGInputActionPair.h"
#include "InputAction.h"

const UInputAction* const UFGPawnInputConfig::Find(const FGameplayTag& InGameplayTag) const
{
	uint32 Index = InputAction_Pairs.IndexOfByPredicate([&](const FGInputAction_Pair_Registered& InEntry)
		{
			return InEntry.GameplayTag_InputAction_Registered == InGameplayTag;
		});
	return Index != INDEX_NONE ? InputAction_Pairs[Index].InputAction_Registered.Get() : nullptr;
}
