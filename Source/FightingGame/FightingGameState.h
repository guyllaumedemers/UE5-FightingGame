// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FightingGameState.generated.h"

UCLASS()
class FIGHTINGGAME_API AFightingGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	FORCEINLINE bool GetCanPlayersMove() const				{ return CanPlayersMove; };
	FORCEINLINE void SetCanPlayersMove(const bool& value)	{ CanPlayersMove = value; }

private:

	bool CanPlayersMove = false;
};
