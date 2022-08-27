#include "MatchSubsystem.h"
#include "FightingGame/Abilities/AttributeSet_World.h"
#include "FightingGame/Abilities/GameplayEffect_World.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

UMatchSubsystem::UMatchSubsystem(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->SetupAbilitySystemComponent_Init<UAttributeSet_World, UGameplayEffect_World>(this);
}

void UMatchSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMatchSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

UAbilitySystemComponent* UMatchSubsystem::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
