#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Actor.h"
#include "Actor_TimerHandler.generated.h"

UCLASS()
class FIGHTINGGAME_API AActor_TimerHandler : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

	// will handle timer ability for round reset and match tracking, not having the GA_Timer will create no time limit mode without additional code
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

protected:

	AActor_TimerHandler(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintGetter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
