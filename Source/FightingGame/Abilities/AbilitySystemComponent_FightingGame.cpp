#include "AbilitySystemComponent_FightingGame.h"
#include "FightingGame/Abilities/AttributeSet_Fighter.h"

void UAbilitySystemComponent_FightingGame::BeginPlay()
{
	Super::BeginPlay();
}

void UAbilitySystemComponent_FightingGame::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UAbilitySystemComponent_FightingGame::UnRegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility)
{
}

void UAbilitySystemComponent_FightingGame::RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility)
{
	check(NewAbility);

	const FGameplayAbilitySpecHandle& AbilitySpecHandle = GiveAbility(FGameplayAbilitySpec(NewAbility));
	AbilitySpecHandles.AddUnique(AbilitySpecHandle);
}
