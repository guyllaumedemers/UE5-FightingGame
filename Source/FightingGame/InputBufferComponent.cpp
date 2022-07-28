// Fill out your copyright notice in the Description page of Project Settings.


#include "InputBufferComponent.h"
#include "FightingCharacterBase.h"
#include "FightingGameState.h"

UInputBufferComponent::UInputBufferComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UInputBufferComponent::CaptureInput(FKey FKey)
{
	const AFightingGameState* FightingGameState = Cast<AFightingGameState>(GetWorld()->GetGameState());
	if(FightingGameState && FightingGameState->GetCanPlayersMove())
	{
		const AFightingCharacterBase* FightingCharacterBase = Cast<AFightingCharacterBase>(GetOwner());
		if(FightingCharacterBase && !FightingCharacterBase->GetIsPlayerCancelled())
		{
			const FInputKey CapturedKey = ConvertFKey(FKey);
			if (IsLastCaptureTimeGreaterThanMaxThreshold(CapturedKey)) ResetInputString();
			else AddKey(CapturedKey);
		}
	}
}

FInputKey UInputBufferComponent::ConvertFKey(const FKey& FKey)
{
	FInputKey result;
	/*
	 *	Do input conversion here, would be cool to have some sort of string parsing system here instead of doing a switch case
	 *
	 */
	return result;
}