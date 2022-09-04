// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FightingGame/Settings/TaggedInputAction_Pair.h"
#include "DataAsset_InputConfig.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<FTaggedInputAction_Pair> InputAction_Pairs;

public:

	const UInputAction* FindInputActionByTag(const FGameplayTag& GameplayTag) const;
	const TArray<FTaggedInputAction_Pair>& GetInputAction_Pairs() const { return InputAction_Pairs; }
};
