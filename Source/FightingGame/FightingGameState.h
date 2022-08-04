// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionTableRow.h"
#include "GameFramework/GameState.h"
#include "FightingGameState.generated.h"

UCLASS()
class FIGHTINGGAME_API AFightingGameState : public AGameState
{
	GENERATED_BODY()

protected:

	AFightingGameState(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

public:

	// Keep Reference to the Mapping of UE5 Inputs and Custom Create Ones
	FORCEINLINE const TMap<FString, FInputKey>& GetUEInputToCustomKeyMap() const	{ return UEInputToCustomKeyMap; }

	// Tracking the GameState, is the cinematic complete
	FORCEINLINE bool GetCanPlayersMove() const										{ return CanPlayersMove; }
	FORCEINLINE void SetCanPlayersMove(const bool& value)							{ CanPlayersMove = value; }

private:

	bool CanPlayersMove = false;

	// Store KeyValuePair for Fkey - FInputKey
	TMap<FString, FInputKey> UEInputToCustomKeyMap;

	void RegisterInputs();

	FInputKey ParseKey(FString);
};
