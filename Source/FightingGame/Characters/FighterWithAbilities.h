#pragma once

#include "CoreMinimal.h"
#include "Fighter.h"
#include "AbilitySystemInterface.h"
#include "FighterWithAbilities.generated.h"

class UAbilitySystemComponent_FightingGame;

UCLASS()
class FIGHTINGGAME_API AFighterWithAbilities : public AFighter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	TObjectPtr<UAbilitySystemComponent_FightingGame> AbilitySystemComponent;

protected:

	AFighterWithAbilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	UFUNCTION(BlueprintGetter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
