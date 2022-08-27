#include "MatchSubsystem.h"
#include "FightingGame/Abilities/AbilitySet_World.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

UMatchSubsystem::UMatchSubsystem(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->SetupAbilitySystemComponent_Init<UAbilitySet_World>();
}

UAbilitySystemComponent* UMatchSubsystem::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
