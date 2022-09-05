// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "HealthComponent.generated.h"

class UAbilitySystemComponent;
class UHealthAttributeSet;

/**
 *
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTINGGAME_API UHealthComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

	UPROPERTY()
	const UHealthAttributeSet* HealthAttributeSet;

public:

	UHealthComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual bool OnPawnReady(const UAbilitySystemComponent& AbilitySystemComponent);
};
