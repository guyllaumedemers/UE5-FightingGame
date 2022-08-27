#include "FighterWithAbilities.h"
#include "FightingGame/Abilities/AttributeSet_Fighter.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

AFighterWithAbilities::AFighterWithAbilities(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->SetupAbilitySystemComponent_Init<UAttributeSet_Fighter>();
}

UAbilitySystemComponent* AFighterWithAbilities::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}