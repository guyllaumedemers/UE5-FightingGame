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
			InputBufferComponent->SubscribeOnInputActionStackConsumed([&](const TArray<const UInputAction*>& InActionStack)
			{
				ParseInputActionStack(InActionStack);
			});
		}
	}
}

void UFGComboParserComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	const AActor* const Owner = GetOwner();
	if (ensureAlways(Owner))
	{
		UFGInputBufferComponent* const InputBufferComponent = Owner->FindComponentByClass<UFGInputBufferComponent>();
		if (ensureAlways(InputBufferComponent))
		{
			InputBufferComponent->UnSubscribeOnInputActionStackConsumed();
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UFGComboParserComponent::ParseInputActionStack(const TArray<const UInputAction*>& InActionStack)
{
	if(!InActionStack.IsEmpty())
	{
		/*Process Combo here*/
	}
}
