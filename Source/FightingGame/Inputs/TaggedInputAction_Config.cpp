#include "TaggedInputAction_Config.h"

const UInputAction* UTaggedInputAction_Config::FindInputActionByTaggedInput(const FGameplayTag& FGameplayTag) const
{
	const auto Index = TaggedInputActions_Pair.IndexOfByPredicate([&](const FTaggedInputAction_Pair& TagInputAction) { return TagInputAction.GetInputGameplayTag() == FGameplayTag; });
	return Index != INDEX_NONE ? TaggedInputActions_Pair[Index].GetInputAction() : nullptr;
}