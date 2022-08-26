#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemComponent_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UAbilitySystemComponent_FightingGame : public UAbilitySystemComponent
{
	GENERATED_BODY()

	// Input Private Fields here

protected:

	UAbilitySystemComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
