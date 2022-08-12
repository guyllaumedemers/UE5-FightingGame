// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGameState.h"
#include "GameFramework/InputSettings.h"
#include "UObject/ConstructorHelpers.h"
#include "EnhancedInput/Public/InputMappingContext.h"

AFightingGameState::AFightingGameState(const FObjectInitializer& FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	CanPlayersMove = true;

	const auto AssetFound = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/ProjectContent/Inputs/Gameplay/IMC_InputRecord.IMC_InputRecord"));
	if (AssetFound.Succeeded()) DefaultInputMappingContext = AssetFound.Object;
}

void AFightingGameState::BeginPlay()
{
	Super::BeginPlay();

	// Parsing Input Mapping Context, Retrieve all IA and Map to usable Data Collection
	if (DefaultInputMappingContext)
	{
		for (const auto& it : DefaultInputMappingContext->GetMappings())
		{
			CustomDefaultInputMappingContext.Add(it.Action, FInputKey::Create(it.Action));
		}

		for (const auto& it : CustomDefaultInputMappingContext)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s %s %s"), *it.Key->GetFName().ToString(), *UEnum::GetDisplayValueAsText(it.Value.KeyHandle).ToString(), *UEnum::GetDisplayValueAsText(it.Value.DirectionalHandle).ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InputMappingContext FAILED TO LOAD FROM REGISTRY"));
	}
}
