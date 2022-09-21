// Fill out your copyright notice in the Description page of Project Settings.


#include "FGHealthComponent.h"

void UFGHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UFGHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
