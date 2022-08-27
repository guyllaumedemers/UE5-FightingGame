#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "Subsystems/WorldSubsystem.h"
#include "MatchSubsystem.generated.h"

UCLASS()
class FIGHTINGGAME_API UMatchSubsystem : public UWorldSubsystem, public IAbilitySystemInterface
{
	GENERATED_BODY()

	// will handle timer ability for round reset and match tracking
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

protected:

	UMatchSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	UFUNCTION(BlueprintGetter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
