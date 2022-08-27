#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemGlobals_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UAbilitySystemGlobals_FightingGame : public UAbilitySystemGlobals
{
	GENERATED_BODY()

protected:

	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
};
