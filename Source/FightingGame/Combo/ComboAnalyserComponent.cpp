// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboAnalyserComponent.h"

UComboAnalyserComponent::UComboAnalyserComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UComboAnalyserComponent::Append(const FInputActionInstance& InputActionInstance)
{
}

void UComboAnalyserComponent::Clear()
{
}
