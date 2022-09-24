// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "FGInputActionPair.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FGInputAction_Pair_Registered /*This will load the Pawn Input Action to listen to on the hardware side*/
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UInputAction> InputAction_Registered;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag_InputAction_Registered;
};

UCLASS()
class FIGHTINGGAME_API UFGPawnInputConfig : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> PawnSubClass;

	UPROPERTY(EditDefaultsOnly)
	TArray<FGInputAction_Pair_Registered> InputAction_Pairs;

public:

	FORCEINLINE const UInputAction* const Find(const FGameplayTag& InGameplayTag) const
	{
		uint32 Index = InputAction_Pairs.IndexOfByPredicate([&](const FGInputAction_Pair_Registered& InEntry) { return InEntry.GameplayTag_InputAction_Registered == InGameplayTag; });
		return Index != INDEX_NONE ? InputAction_Pairs[Index].InputAction_Registered.Get() : nullptr;
	}

	const TArray<FGInputAction_Pair_Registered>& GetInputBindingPairs() const { return InputAction_Pairs; }
};