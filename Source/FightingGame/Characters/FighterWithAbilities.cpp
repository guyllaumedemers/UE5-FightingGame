#include "FighterWithAbilities.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

UAbilitySystemComponent* AFighterWithAbilities::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}

const UAbilitySystemComponent_FightingGame* AFighterWithAbilities::GetAbilitySystemComponentDerived() const
{
	return Cast<UAbilitySystemComponent_FightingGame>(GetAbilitySystemComponent());
}
