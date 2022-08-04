// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingCharacterBase.h"
#include "InputBufferComponent.h"

AFightingCharacterBase::AFightingCharacterBase(const FObjectInitializer& ObjectInitializer) : PlayerInputBufferComponent(nullptr)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	PlayerInputBufferComponent = CreateDefaultSubobject<UInputBufferComponent>(TEXT("PlayerInputBuffer"));
}

void AFightingCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}
