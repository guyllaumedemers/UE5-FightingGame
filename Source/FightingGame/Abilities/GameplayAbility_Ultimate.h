#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbility_Ultimate.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameplayAbility_Ultimate : public UGameplayAbility
{
	GENERATED_BODY()

protected:

	UGameplayAbility_Ultimate(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
