#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTags.h"
#include "Engine/DataAsset.h"
#include "TaggedInputActionConfig.generated.h"

class UInputAction;

UCLASS()
class UTaggedInputActionConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	const UInputAction* FindInputActionByTaggedInput(const FGameplayTag& FGameplayTag) const;

	UPROPERTY(EditAnywhere);
	TArray<FTaggedInputAction> TaggedInputActions;
};
