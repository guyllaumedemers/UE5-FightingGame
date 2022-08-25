#include "TaggedInputActionConfig.h"

const UInputAction* UTaggedInputActionConfig::FindInputActionByTaggedInput(const FGameplayTag& FGameplayTag) const
{
	const auto Index = TaggedInputActions.IndexOfByPredicate([&](const FTaggedInputAction& TagInputAction) { return TagInputAction.GameplayTag == FGameplayTag; });
	return Index != INDEX_NONE ? TaggedInputActions[Index].InputAction : nullptr;
}