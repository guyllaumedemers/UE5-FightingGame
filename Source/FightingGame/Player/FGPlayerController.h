// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API AFGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
