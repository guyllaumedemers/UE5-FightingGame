#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility_Fighter.h"
#include "GameplayAbility_RageDrive.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameplayAbility_RageDrive : public UGameplayAbility_Fighter
{
	GENERATED_BODY()

protected:

	UGameplayAbility_RageDrive(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void OnRemoveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
};
