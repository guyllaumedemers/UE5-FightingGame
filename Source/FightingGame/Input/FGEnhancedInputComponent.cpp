// Fill out your copyright notice in the Description page of Project Settings.


#include "FGEnhancedInputComponent.h"

void UFGEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UFGEnhancedInputComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UFGEnhancedInputComponent::RegisterHardwareInputBindings()
{
}

void UFGEnhancedInputComponent::UnRegisterHardwareInputBindings()
{
}
