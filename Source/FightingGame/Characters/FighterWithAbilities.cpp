#include "FighterWithAbilities.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

AFighterWithAbilities::AFighterWithAbilities(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");
}

UAbilitySystemComponent* AFighterWithAbilities::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());
}