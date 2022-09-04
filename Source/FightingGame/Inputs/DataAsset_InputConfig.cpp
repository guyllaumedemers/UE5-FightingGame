// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAsset_InputConfig.h"

const UInputAction* UDataAsset_InputConfig::FindInputActionByTag(const FGameplayTag& GameplayTag) const
{
	uint16 Index = InputAction_Pairs.IndexOfByPredicate([&](const FTaggedInputAction_Pair& Entry_Pair) { return Entry_Pair.GetGameplayTag() == GameplayTag; });
	return Index != INDEX_NONE ? InputAction_Pairs[Index].GetInputAction() : nullptr;
}
