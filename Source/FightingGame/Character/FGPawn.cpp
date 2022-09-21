// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPawn.h"
#include "FGHealthComponent.h"
#include "FGHitBoxDetectionComponent.h"

AFGPawn::AFGPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	HitBoxDetectionComponent = CreateDefaultSubobject<UFGHitBoxDetectionComponent>(UFGHitBoxDetectionComponent::StaticClass()->GetFName());
	HealthComponent = CreateDefaultSubobject<UFGHealthComponent>(UFGHealthComponent::StaticClass()->GetFName());
}

void AFGPawn::BeginPlay()
{
	Super::BeginPlay();
}

void AFGPawn::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
