// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FGHealthAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	FGameplayAttributeData MaxHealth;
	FGameplayAttributeData CurrentHealth;
	FGameplayAttributeData DamageTaken;

public:

	/*
	 *	Require Wireframing architectural decision
	 */
};
