// Fill out your copyright notice in the Description page of Project Settings.


#include "FGComboParserComponent.h"
#include "FGInputBufferComponent.h"

void UFGComboParserComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	const AActor* const Owner = GetOwner();
	if(ensureAlways(Owner))
	{
		UFGInputBufferComponent* const InputBufferComponent = Owner->FindComponentByClass<UFGInputBufferComponent>();
		if (ensureAlways(InputBufferComponent))
		{
			InputBufferComponent->Subscribe([&](const UInputAction* InAction) { return IsValidCapture(InAction); }); /* (*this).IsValidCapture not working... why? TFunctionRef passed by const Reference.*/
		}
	}
}

void UFGComboParserComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

bool UFGComboParserComponent::IsValidCapture(const UInputAction* InAction)
{

	return true;
}
