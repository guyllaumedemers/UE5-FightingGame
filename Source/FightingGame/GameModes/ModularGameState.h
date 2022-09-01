// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "ModularGameState.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API AModularGameState : public AGameState
{
	GENERATED_BODY()

public:

	//~AActor INTERFACE
	AModularGameState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~AActor INTERFACE
};
