// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FGEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	void RegisterHardwareInputBindings();
	void UnRegisterHardwareInputBindings();
};
