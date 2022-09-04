// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FightingGame/Settings/TaggedInputAction_Pair.h"
#include "InputConfig.generated.h"

class UInputConfig;
class UInputAction;
class APawn;

struct FInputConfig_Loaded
{
	FInputConfig_Loaded(const UInputConfig* InConfig)
		: InputConfig(InConfig)
	{}

	FInputConfig_Loaded()
		: InputConfig(nullptr)
	{}

	const UInputConfig* GetInputConfig() const { return InputConfig; }

private:

	const UInputConfig* InputConfig;
};

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UInputConfig : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<APawn> PawnSubClass;

	UPROPERTY(EditDefaultsOnly)
	TArray<FTaggedInputAction_Pair> InputAction_Pairs;

public:

	const TArray<FTaggedInputAction_Pair>& GetInputAction_Pairs() const { return InputAction_Pairs; }
	const UInputAction* FindInputActionByTag(const FGameplayTag& GameplayTag) const;

	static void Register(const TSoftObjectPtr<UInputConfig>& InputConfig);
	static void Unregister(const TSoftObjectPtr<UInputConfig>& InputConfig);
	static void Activate(const TSoftObjectPtr<UInputConfig>& InputConfig);
	static void Deactivate(const TSoftObjectPtr<UInputConfig>& InputConfig);
};
