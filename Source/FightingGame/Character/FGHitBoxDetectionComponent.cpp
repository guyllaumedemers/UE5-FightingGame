// Fill out your copyright notice in the Description page of Project Settings.


#include "FGHitBoxDetectionComponent.h"
#include "InputAction.h"
#include "FightingGame/Player/FGInputBufferComponent.h"

void UFGHitBoxDetectionComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	const AActor* const Owner = GetOwner();
	if (ensureAlways(Owner))
	{
		UFGInputBufferComponent* const InputBufferComponent = Owner->FindComponentByClass<UFGInputBufferComponent>();
		if (ensureAlways(InputBufferComponent))
		{
			InputBufferComponent->SubscribeOnInputActionRegistered([&](const UInputAction* InAction)
			{
				return IsActorInputActionPerformed(InAction);
			});
		}
	}
}

void UFGHitBoxDetectionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	const AActor* const Owner = GetOwner();
	if (ensureAlways(Owner))
	{
		UFGInputBufferComponent* const InputBufferComponent = Owner->FindComponentByClass<UFGInputBufferComponent>();
		if (ensureAlways(InputBufferComponent))
		{
			InputBufferComponent->UnSubscribeOnInputActionRegistered();
		}
	}

	Super::EndPlay(EndPlayReason);
}

bool UFGHitBoxDetectionComponent::IsActorInputActionPerformed(const UInputAction* InAction)
{
	/*Calculate Frame Data +2, -2 here*/
	return true /*return condition state here*/;
}
