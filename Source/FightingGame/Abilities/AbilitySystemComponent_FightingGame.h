#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemComponent_FightingGame.generated.h"

class UAbilitySet_Fighter;

UCLASS()
class FIGHTINGGAME_API UAbilitySystemComponent_FightingGame : public UAbilitySystemComponent
{
	GENERATED_BODY()

	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	void RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility);

	TSoftObjectPtr<UAbilitySet_Fighter> AbilitySet;

protected:

	UAbilitySystemComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
