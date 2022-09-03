// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ModularPlayerController.generated.h"

/**
 *
 */
UCLASS(Abstract)
class FIGHTINGGAME_API AModularPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AModularPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:

	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
