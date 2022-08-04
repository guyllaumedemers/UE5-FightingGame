// Fill out your copyright notice in the Description page of Project Settings.


#include "InputBufferComponent.h"
#include "FightingCharacterBase.h"
#include "FightingGameState.h"
#include "GameFramework/InputSettings.h"

UInputBufferComponent::UInputBufferComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UInputBufferComponent::CaptureInput(FKey FKey)
{
	const AFightingGameState* FightingGameState = Cast<AFightingGameState>(GetWorld()->GetGameState());
	if (FightingGameState && FightingGameState->GetCanPlayersMove())
	{
		const AFightingCharacterBase* FightingCharacterBase = Cast<AFightingCharacterBase>(GetOwner());
		if (FightingCharacterBase && !FightingCharacterBase->GetIsPlayerCancelled())
		{
			const FInputKey CapturedKey = GetFInputKey(FKey);
			if (IsValidKey(CapturedKey))
			{
				if (IsLastCaptureTimeGreaterThanMaxThreshold(CapturedKey)) ResetInputString();
				else AddKey(CapturedKey);
			}
		}
	}
}

FInputKey UInputBufferComponent::GetFInputKey(const FKey& FKey)
{
	const AFightingGameState* FightingGameState = Cast<AFightingGameState>(GetWorld()->GetGameState());
	if(FightingGameState)
	{
		const FString KeyPressed = FKey.GetFName().ToString();
		const TMap<FString, FInputKey> UEInputToCustomKeyMap = FightingGameState->GetUEInputToCustomKeyMap();
		if (UEInputToCustomKeyMap.Find(KeyPressed)) return UEInputToCustomKeyMap[KeyPressed];
	}
	return FInputKey();
}
