// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "ComboAnalyserComponent.generated.h"

struct FInputActionInstance;
struct FCombo;

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FIGHTINGGAME_API UComboAnalyserComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:

	UComboAnalyserComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	void Append(const FInputActionInstance& InputActionInstance);
	void Clear();
};
