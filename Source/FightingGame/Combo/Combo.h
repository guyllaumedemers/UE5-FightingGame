// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Combo.generated.h"

class UInputAction;

USTRUCT()
struct FCombo_SimpleEntry
{
	GENERATED_BODY()

	FCombo_SimpleEntry()
		: Threshold(0.f)
	{}

	float GetThreshold() const { return Threshold; }

private:

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UInputAction> InputAction;

	UPROPERTY(EditDefaultsOnly, meta = (ShortTooltip = "Time between CurrentEntry & NextEntry trigger"))
	float Threshold;
};

USTRUCT()
struct FCombo_ComplexEntry
{
	GENERATED_BODY()

	FCombo_ComplexEntry()
		: SimpleEntries(TArray<FCombo_SimpleEntry>())
		, Threshold(0.f)
	{}

private:

	UPROPERTY(EditDefaultsOnly)
	TArray<FCombo_SimpleEntry> SimpleEntries;

	UPROPERTY(EditDefaultsOnly, meta = (ShortTooltip = "Time between CurrentEntry & NextEntry trigger"))
	float Threshold;
};

/**
 * 
 */
USTRUCT()
struct FCombo
{
	GENERATED_BODY()

	FCombo()
		: Entries(TArray<FCombo_ComplexEntry>())
	{}

	bool CanPerform() const { return Entries.IsEmpty(); }

private:

	UPROPERTY(EditDefaultsOnly)
	TArray<FCombo_ComplexEntry> Entries;
};
