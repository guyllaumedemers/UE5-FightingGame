#include "GameplayEffect_Fighter.h"
#include "AttributeSet_Fighter.h"

UGameplayEffect_Fighter::UGameplayEffect_Fighter(const FObjectInitializer& ObjectInitializer)
{
	FGameplayModifierInfo RageDrive;
	FGameplayModifierInfo Health;
	FGameplayModifierInfo BaseDamage;

	FGameplayEffectModifierMagnitude RageMagnitude(FScalableFloat(0.f));
	FGameplayEffectModifierMagnitude DamageMagnitude(FScalableFloat(8.f));
	FGameplayEffectModifierMagnitude HealthMagnitude(FScalableFloat(100.f));

	SetGameplayModifierInfo(RageDrive,
		UAttributeSet_Fighter::GetRageDriveAttribute(),
		EGameplayModOp::Override,
		RageMagnitude,
		FGameplayTagRequirements(),
		FGameplayTagRequirements()
	);

	SetGameplayModifierInfo(Health,
		UAttributeSet_Fighter::GetHealthAttribute(),
		EGameplayModOp::Override,
		HealthMagnitude,
		FGameplayTagRequirements(),
		FGameplayTagRequirements()
	);

	SetGameplayModifierInfo(BaseDamage,
		UAttributeSet_Fighter::GetHealthAttribute(),
		EGameplayModOp::Override,
		DamageMagnitude,
		FGameplayTagRequirements(),
		FGameplayTagRequirements()
	);
}
