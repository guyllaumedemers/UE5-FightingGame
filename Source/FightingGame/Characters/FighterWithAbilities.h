// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Fighter.h"
#include "AbilitySystemInterface.h"
#include "FighterWithAbilities.generated.h"

class UAbilitySystemComponent_FightingGame;

UCLASS()
class FIGHTINGGAME_API AFighterWithAbilities : public AFighter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	TObjectPtr<UAbilitySystemComponent_FightingGame> AbilitySystemComponent;
	// seem like redundant as it upcast to the base class than gets call with a Cast<> to its derived class in the method below
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:

	UFUNCTION(BlueprintGetter)
	const UAbilitySystemComponent_FightingGame* GetAbilitySystemComponentDerived() const;
};
