// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character_Fighter.h"
#include "Character_FighterWithAbilities.generated.h"

class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API ACharacter_FighterWithAbilities : public ACharacter_Fighter
{
	GENERATED_BODY()

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

public:

	ACharacter_FighterWithAbilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
