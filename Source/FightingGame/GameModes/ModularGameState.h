// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/GameState.h"
#include "ModularGameState.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FIGHTINGGAME_API AModularGameState : public AGameState
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (ShortTooltip = "GameState Tag Handle"))
	FGameplayTagContainer GameplayTagContainer;

public:

	AModularGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	const FGameplayTagContainer& GetGameplayTagContainer() const { return GameplayTagContainer; }
};
