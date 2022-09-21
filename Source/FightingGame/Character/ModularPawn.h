// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ModularPawn.generated.h"

UCLASS(Abstract)
class FIGHTINGGAME_API AModularPawn : public APawn
{
	GENERATED_BODY()

public:

	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnPosses() {};
	virtual void OnUnPossess() {};
};
