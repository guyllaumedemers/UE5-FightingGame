#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTag_FightingGame.h"
#include "Engine/DataAsset.h"
#include "TaggedInputAction_Config.generated.h"

class UInputAction;

UCLASS()
class UTaggedInputAction_Config : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly);
	TArray<FTaggedInputAction_Pair> TaggedInputActions_Pair;

public:

	const UInputAction* FindInputActionByTaggedInput(const FGameplayTag& FGameplayTag) const;
};
