#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemComponent_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UAbilitySystemComponent_FightingGame : public UAbilitySystemComponent
{
	GENERATED_BODY()

	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;
	void RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility);

	TSoftObjectPtr<UGameplayAbilitySet> AbilitySet;

protected:

	UAbilitySystemComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};

public:

	template<typename UserClass>
	void SetupAbilitySystemComponent_Init();
};

template <typename UserClass>
void UAbilitySystemComponent_FightingGame::SetupAbilitySystemComponent_Init()
{
	AbilitySet = GetSet<UserClass>();
}
