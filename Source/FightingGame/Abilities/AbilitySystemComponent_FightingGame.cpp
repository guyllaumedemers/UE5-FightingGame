#include "AbilitySystemComponent_FightingGame.h"
#include "FightingGame/Abilities/AbilitySet_Fighter.h"

void UAbilitySystemComponent_FightingGame::RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility)
{
	check(NewAbility);

	const FGameplayAbilitySpecHandle& AbilitySpecHandle = GiveAbility(FGameplayAbilitySpec(NewAbility));
	AbilitySpecHandles.AddUnique(AbilitySpecHandle);
}
