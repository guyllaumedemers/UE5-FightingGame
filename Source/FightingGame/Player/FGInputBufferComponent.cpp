// Fill out your copyright notice in the Description page of Project Settings.


#include "FGInputBufferComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

#ifndef FRAMERATE
#define FRAMERATE 60
#endif

#ifndef SECOND
#define SECOND 1000
#endif

#ifndef FRAMEINTERVAL
#define FRAMEINTERVAL 3
#endif

void UFGInputBufferComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;

	const UWorld* const World = GetWorld();
	if (ensureAlways(World))
	{
		FTimerManager& TimerManager = World->GetTimerManager();
		TimerManager.SetTimer(TimerHandle, this, &UFGInputBufferComponent::Clear, (SECOND/FRAMERATE) * FRAMEINTERVAL, true);
	}
}

void UFGInputBufferComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	const UWorld* const World = GetWorld();
	if (ensureAlways(World))
	{
		FTimerManager& TimerManager = World->GetTimerManager();
		TimerManager.ClearAllTimersForObject(this);
	}

	Super::EndPlay(EndPlayReason);
}
