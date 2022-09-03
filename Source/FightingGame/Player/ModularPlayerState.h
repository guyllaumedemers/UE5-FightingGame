// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ModularPlayerState.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FIGHTINGGAME_API AModularPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	AModularPlayerState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
