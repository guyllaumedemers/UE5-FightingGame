// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularPawn.h"
#include "FGPlayerPawn.generated.h"

class UFGInputBufferComponent;

UCLASS()
class FIGHTINGGAME_API AFGPlayerPawn : public AModularPawn
{
	GENERATED_BODY()

	const UFGInputBufferComponent* InputBufferComponent;

public:

	AFGPlayerPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void OnPosses() override;
	virtual void OnUnPossess() override;
};
