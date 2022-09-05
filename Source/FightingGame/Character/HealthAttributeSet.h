// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData CurrentHealth;

	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData MaxHealth;

	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData DamageDealt;

public:

	UHealthAttributeSet()
		: CurrentHealth(1.f)
		, MaxHealth(1.f)
		, DamageDealt(0.f)
	{}

	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, CurrentHealth);
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, DamageDealt);
};
