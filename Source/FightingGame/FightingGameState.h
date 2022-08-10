// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionTableRow.h"
#include "InputMappingContext.h"
#include "GameFramework/GameState.h"
#include "FightingGameState.generated.h"

USTRUCT()
struct FMatchOutcomeInfo
{
	GENERATED_BODY()

		/*
		 *	To Be Defined, which player won? how much a player gain? how much a player lose
		 */
};

USTRUCT()
struct FRoundOutcomeInfo
{
	GENERATED_BODY()

		/*
		 *	To Be Defined, which player get the Round Point? notify client widgets for update on both end, etc... Reset Character position, etc... Play Cinematic for Round Startup
		 */
};

class UInputMappingContext;

UCLASS()
class FIGHTINGGAME_API AFightingGameState : public AGameState
{
	GENERATED_BODY()

protected:

	AFightingGameState(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

	virtual void BeginPlay() override;

public:

	// Keep Reference to the Mapping of UE5 Inputs and Custom Create Ones
	FORCEINLINE TSoftObjectPtr<UInputMappingContext> GetDefaultInputMappingContext() const	{ return DefaultInputMappingContext; }
	FORCEINLINE FInputKey GetFInputKey(const UInputAction* Value) const						{ return GetInputActionKeyValue(Value); }

	// Tracking the GameState, is the cinematic complete
	FORCEINLINE bool GetCanPlayersMove() const												{ return CanPlayersMove; }
	FORCEINLINE void SetCanPlayersMove(const bool& Value)									{ CanPlayersMove = Value; }

	FORCEINLINE void BroadcastMatchOutcome(const FMatchOutcomeInfo& MatchOutcomeInfo) const	{ OnMatchOutcomeDefinedDelEvent.ExecuteIfBound(MatchOutcomeInfo); }
	FORCEINLINE void BroadcastRoundOutcome(const FRoundOutcomeInfo& RoundOutcomeInfo) const { OnRoundOutcomeDefinedDelEvent.ExecuteIfBound(RoundOutcomeInfo); }

	/*
	 *	Research how to Run the Del Binding while keeping things encapsulated inside the GameState?
	 *
	 */

private:

	// IMC use for IA Retrieval, while TMap use for KeyValuePair assignment. TO BE USE with Custom Bitmask flag system
	TSoftObjectPtr<UInputMappingContext> DefaultInputMappingContext;
	TMap<TSoftObjectPtr<UInputAction>, FInputKey> CustomDefaultInputMappingContext;

	FORCEINLINE bool IsInputActionFound(const UInputAction* InputAction) const				{ return CustomDefaultInputMappingContext.Find(InputAction) != nullptr; }
	FORCEINLINE FInputKey GetInputActionKeyValue(const UInputAction* InputAction) const		{ return IsInputActionFound(InputAction) ? CustomDefaultInputMappingContext[InputAction] : FInputKey(); }

	bool CanPlayersMove = false;

	DECLARE_DELEGATE_OneParam(OnMatchOutcomeDefined, FMatchOutcomeInfo)
	OnMatchOutcomeDefined OnMatchOutcomeDefinedDelEvent;

	DECLARE_DELEGATE_OneParam(OnRoundOutcomeDefined, FRoundOutcomeInfo)
	OnRoundOutcomeDefined OnRoundOutcomeDefinedDelEvent;

};
