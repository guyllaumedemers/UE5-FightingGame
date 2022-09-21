// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "ModularPawn.h"
#include "FGPlayerPawn.generated.h"

class UFGInputBufferComponent;

UCLASS()
class FIGHTINGGAME_API AFGPlayerPawn : public AModularPawn
{
	GENERATED_BODY()

	TObjectPtr<UFGInputBufferComponent> InputBufferComponent;

public:

	AFGPlayerPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void OnPosses() override;
	virtual void OnUnPossess() override;

public:

	void OnCapture(const FInputActionInstance& InputActionInstance);
};
