#include "AbilitySystemComponent_FightingGame.h"
#include "FightingGame/Abilities/AbilitySet_Fighter.h"

UAbilitySystemComponent_FightingGame::UAbilitySystemComponent_FightingGame(const FObjectInitializer& ObjectInitializer)
{
	AbilitySet = GetSet<UAbilitySet_Fighter>();
}

void UAbilitySystemComponent_FightingGame::RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility)
{
	check(NewAbility);

	const FGameplayAbilitySpecHandle& AbilitySpecHandle = GiveAbility(FGameplayAbilitySpec(NewAbility));
	AbilitySpecHandles.AddUnique(AbilitySpecHandle);
}
