// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputComponent_FightingGame.generated.h"

class ULocalPlayer;
struct FPlayerMappableInput_Loaded;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UEnhancedInputComponent_FightingGame : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:

	UEnhancedInputComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {}
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void OnPossess(const FPlayerMappableInput_Loaded& MappingContext_Pair, APawn* Pawn);
	void OnUnPossess(const FPlayerMappableInput_Loaded& MappingContext_Pair, APawn* Pawn);


private:

	void Register(const FPlayerMappableInput_Loaded& MappingContext_Pair, ULocalPlayer* LocalPlayer);
	void Unregister(const FPlayerMappableInput_Loaded& MappingContext_Pair, ULocalPlayer* LocalPlayer);
};
