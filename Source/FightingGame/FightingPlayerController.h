// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FightingPlayerController.generated.h"

UCLASS()
class FIGHTINGGAME_API AFightingPlayerController : public APlayerController
{
	GENERATED_BODY()

	AFightingPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupInputComponent() override;

private:

	UFUNCTION()
	void BindPlayerControllerInputs(APawn* OldPawnControlled, APawn* NewPawnControlled);
};
