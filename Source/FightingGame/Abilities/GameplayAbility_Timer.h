#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility_World.h"
#include "GameplayAbility_Timer.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameplayAbility_Timer : public UGameplayAbility_World
{
	GENERATED_BODY()

protected:

	UGameplayAbility_Timer(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
