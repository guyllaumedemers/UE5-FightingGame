// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "FGRageDriveAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGRageDriveAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	FGameplayAttributeData MaxRageDrive;
	FGameplayAttributeData CurrentRageDrive;

public:

	/*
	 *	Require Wireframing architectural decision
	 */
};
