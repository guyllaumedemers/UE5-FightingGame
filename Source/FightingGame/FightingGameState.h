// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FightingGameState.generated.h"

UCLASS()
class FIGHTINGGAME_API AFightingGameState : public AGameState
{
	GENERATED_BODY()

public:

	AFightingGameState(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

	// Tracking the GameState, is the cinematic complete
	FORCEINLINE bool GetCanPlayersMove() const				{ return CanPlayersMove; };
	FORCEINLINE void SetCanPlayersMove(const bool& value)	{ CanPlayersMove = value; }

private:

	bool CanPlayersMove = false;
};
