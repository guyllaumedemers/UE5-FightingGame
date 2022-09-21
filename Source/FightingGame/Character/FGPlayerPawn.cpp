// Fill out your copyright notice in the Description page of Project Settings.


#include "FGPlayerPawn.h"
#include "FightingGame/Player/FGInputBufferComponent.h"

AFGPlayerPawn::AFGPlayerPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	InputBufferComponent = CreateDefaultSubobject<UFGInputBufferComponent>(UFGInputBufferComponent::StaticClass()->GetFName());
}

void AFGPlayerPawn::OnPosses()
{
	Super::OnPosses();
}

void AFGPlayerPawn::OnUnPossess()
{
	Super::OnUnPossess();
}
