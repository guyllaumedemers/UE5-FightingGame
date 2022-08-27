#include "FighterWithAbilities.h"
#include "FightingGame/Abilities/AttributeSet_Fighter.h"
#include "FightingGame/Abilities/GameplayEffect_Fighter.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

AFighterWithAbilities::AFighterWithAbilities(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");
}

void AFighterWithAbilities::BeginPlay()
{
	Super::BeginPlay();
}

void AFighterWithAbilities::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AFighterWithAbilities::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->InitAbilityActorInfo(this, this);
	ASC->SetupAbilitySystemComponent_Init<UAttributeSet_Fighter, UGameplayEffect_Fighter>(this);
}

UAbilitySystemComponent* AFighterWithAbilities::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
