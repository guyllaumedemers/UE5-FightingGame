#include "AbilitySystemComponentHandle_World.h"
#include "FightingGame/Abilities/AttributeSet_World.h"
#include "FightingGame/Abilities/GameplayEffect_World.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

AAbilitySystemComponentHandle_World::AAbilitySystemComponentHandle_World(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");
}

void AAbilitySystemComponentHandle_World::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->InitAbilityActorInfo(this, this);
	ASC->SetupAbilitySystemComponent_Init<UAttributeSet_World, UGameplayEffect_World>(this);
}

void AAbilitySystemComponentHandle_World::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

UAbilitySystemComponent* AAbilitySystemComponentHandle_World::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
