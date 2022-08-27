#include "Actor_TimerHandler.h"
#include "FightingGame/Abilities/AttributeSet_World.h"
#include "FightingGame/Abilities/GameplayEffect_World.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

AActor_TimerHandler::AActor_TimerHandler(const FObjectInitializer& ObjectInitializer)
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent_FightingGame>("Ability System Component");
}

void AActor_TimerHandler::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);

	UAbilitySystemComponent_FightingGame* ASC = Cast<UAbilitySystemComponent_FightingGame>(AbilitySystemComponent.Get());

	check(ASC);

	ASC->InitAbilityActorInfo(this, this);
	ASC->SetupAbilitySystemComponent_Init<UAttributeSet_World, UGameplayEffect_World>(this);
}

void AActor_TimerHandler::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

UAbilitySystemComponent* AActor_TimerHandler::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent.Get();
}
