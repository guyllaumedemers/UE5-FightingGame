// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "ModularGameMode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class FIGHTINGGAME_API AModularGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	//~AActor INTERFACE
	AModularGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~AActor INTERFACE
	
};
