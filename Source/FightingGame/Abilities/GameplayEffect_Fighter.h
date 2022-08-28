#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayEffect_Fighter.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameplayEffect_Fighter : public UGameplayEffect
{
	GENERATED_BODY()

	void SetGameplayModifierInfo(FGameplayModifierInfo& OutModifier,
		FGameplayAttribute GameplayAttribute,
		EGameplayModOp::Type,
		FGameplayEffectModifierMagnitude ModifierMagnitude,
		FGameplayTagRequirements SourceTags,
		FGameplayTagRequirements TargetTags
	);

protected:

	UGameplayEffect_Fighter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};
