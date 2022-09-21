// Fill out your copyright notice in the Description page of Project Settings.


#include "FGHitBoxDetectionComponent.h"

void UFGHitBoxDetectionComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UFGHitBoxDetectionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
