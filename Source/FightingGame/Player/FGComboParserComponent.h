// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FGComboParserComponent.generated.h"

UENUM()
enum EInputBitmask
{
	None = 0,
	D = (1 << 0),
	F = (1 << 1),
	B = (1 << 2),
	U = (1 << 3),
	Fb1 = (1 << 4),
	Fb2 = (1 << 5),
	Fb3 = (1 << 6),
	Fb4 = (1 << 7),
};

class UInputAction;

USTRUCT()
struct FCombo_Pair
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EInputBitmask> InputKey;
};

struct FCombo_Loaded
{
	FCombo_Loaded(const EInputBitmask& InBitmask)
		: InputBitmask(InBitmask)
	{}

	EInputBitmask InputBitmask;
};

class UInputAction;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FIGHTINGGAME_API UFGComboParserComponent : public UActorComponent
{
	GENERATED_BODY()

	TArray<FCombo_Loaded> ComboToPerform;

	FORCEINLINE void Add(const FCombo_Pair* const InCombo_Pair)
	{
		if (ensure(InCombo_Pair))
		{
			const FCombo_Loaded& Combo_Loaded = FCombo_Loaded(InCombo_Pair->InputKey);

			bool Result
				= FindMatchOrAdd(Combo_Loaded);

			if(!Result)
			{
				ComboToPerform.Add(Combo_Loaded);
			}
		}
	}

	FORCEINLINE void Clear()
	{
		/*Do something to reset Current Combo String after timer complete*/
	}

	FORCEINLINE bool FindMatchOrAdd(const FCombo_Loaded& InCombo_Loaded)
	{
		bool MatchFound
			= false /* look for match here*/;
		if(MatchFound)
		{
			/*notify listeners*/
		}
		return MatchFound;
	}

public:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void ParseInputActionStack(const TArray<const UInputAction*>& InActionStack);
};
