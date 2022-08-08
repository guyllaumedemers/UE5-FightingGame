// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionTableRow.h"
#include "InputMappingContext.h"
#include "GameFramework/GameState.h"
#include "FightingGameState.generated.h"

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

private:

	FORCEINLINE bool IsInputActionFound(const UInputAction* InputAction) const				{ return CustomDefaultInputMappingContext.Find(InputAction) != nullptr; }
	FORCEINLINE FInputKey GetInputActionKeyValue(const UInputAction* InputAction) const		{ return IsInputActionFound(InputAction) ? CustomDefaultInputMappingContext[InputAction] : FInputKey(); }

	bool CanPlayersMove = false;

	// IMC use for IA Retrieval, while TMap use for KeyValuePair assignment. TO BE USE with Custom Bitmask flag system
	TSoftObjectPtr<UInputMappingContext> DefaultInputMappingContext;
	TMap<UInputAction*, FInputKey> CustomDefaultInputMappingContext;

};
