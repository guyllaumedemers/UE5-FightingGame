// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "RageDriveAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API URageDriveAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData CurrentRageDriveLevel;

	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData MaxRageDriveLevel;

public:

	URageDriveAttributeSet()
		: CurrentRageDriveLevel(0.f)
		, MaxRageDriveLevel(1.f)
	{}

	ATTRIBUTE_ACCESSORS(URageDriveAttributeSet, CurrentRageDriveLevel);
	ATTRIBUTE_ACCESSORS(URageDriveAttributeSet, MaxRageDriveLevel);
};
