// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "FightingGame/Character/HealthAttributeSet.h"
#include "AbilitySystemComponent.h"

UHealthComponent::UHealthComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HealthAttributeSet = nullptr;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

bool UHealthComponent::OnPawnReady(const UAbilitySystemComponent& AbilitySystemComponent)
{
	return (HealthAttributeSet = AbilitySystemComponent.GetSet<UHealthAttributeSet>()) != nullptr;
}
