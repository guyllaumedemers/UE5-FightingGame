#pragma once

#include "CoreMinimal.h"
#include "Fighter.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "FighterWithAbilities.generated.h"

UCLASS()
class FIGHTINGGAME_API AFighterWithAbilities : public AFighter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

protected:

	AFighterWithAbilities(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PossessedBy(AController* NewController) override;

public:

	UFUNCTION(BlueprintGetter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
