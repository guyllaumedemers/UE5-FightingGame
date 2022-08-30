#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponentHandle_World.generated.h"

UCLASS()
class FIGHTINGGAME_API AAbilitySystemComponentHandle_World : public AActor, public IAbilitySystemInterface
{
	GENERATED_BODY()

	// will handle timer ability for round reset and match tracking, not having the GA_Timer will create no time limit mode without additional code
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

protected:

	AAbilitySystemComponentHandle_World(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	UFUNCTION(BlueprintGetter)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
