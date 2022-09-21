// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "FGInputActionPair.generated.h"

class UInputAction;

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

	const UInputAction* const Find(const FGameplayTag& InGameplayTag) const;

	const TArray<FGInputAction_Pair_Registered>& GetInputPairs() const { return InputAction_Pairs; }
};

struct FGPawnInputConfig_Loaded /*This will cache the Pair InputAction-GameplayTag during runtime*/
{
	FGPawnInputConfig_Loaded(const UFGPawnInputConfig* const InPawnInputConfig, const APawn* const InPawnSubclass)
		: PawnInputConfig(InPawnInputConfig)
		, PawnSubclass(InPawnSubclass)
	{}

	const UFGPawnInputConfig* const PawnInputConfig;
	const APawn* const PawnSubclass;
};
