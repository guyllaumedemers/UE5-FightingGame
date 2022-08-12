// Fill out your copyright notice in the Description page of Project Settings.


#include "InputBufferComponent.h"
#include "FightingCharacterBase.h"
#include "FightingGameState.h"

UInputBufferComponent::UInputBufferComponent(const FObjectInitializer& ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UInputBufferComponent::CaptureInput(const FInputActionInstance& FInputActionInstance)
{
	const AFightingGameState* FightingGameState = Cast<AFightingGameState>(GetWorld()->GetGameState());
	if (FightingGameState && FightingGameState->GetCanPlayersMove())
	{
		const AFightingCharacterBase* FightingCharacterBase = Cast<AFightingCharacterBase>(GetOwner());
		if (FightingCharacterBase && !FightingCharacterBase->GetIsPlayerCancelled())
		{
			const FInputKey CapturedKey = GetFInputKey(FInputActionInstance);
			if (IsValidKey(CapturedKey))
			{
				FString Msg = FInputActionInstance.GetSourceAction()->GetFName().ToString();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, *Msg);

				if (IsLastCaptureTimeGreaterThanMaxThreshold(CapturedKey)) ResetInputString();
				else AddKey(CapturedKey);
			}
		}
	}
}

FInputKey UInputBufferComponent::GetFInputKey(const FInputActionInstance& FInputActionInstance) const
{
	if(const AFightingGameState* FightingGameState = Cast<AFightingGameState>(GetWorld()->GetGameState())) return FightingGameState->GetFInputKey(FInputActionInstance.GetSourceAction());
	return FInputKey();
}
