#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayEffect_World.generated.h"

UCLASS()
class FIGHTINGGAME_API UGameplayEffect_World : public UGameplayEffect
{
	GENERATED_BODY()

protected:

	UGameplayEffect_World(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	
};
