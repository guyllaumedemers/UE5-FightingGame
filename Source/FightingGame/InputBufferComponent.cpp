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
			const FInputKey CapturedKey = ConvertFKey(FKey);
			if (IsValidKey(CapturedKey))
			{
				UE_LOG(LogTemp, Warning, TEXT("%s"), CapturedKey.KeyHandle);
				if (IsLastCaptureTimeGreaterThanMaxThreshold(CapturedKey)) ResetInputString();
				else AddKey(CapturedKey);
			}
		}
	}
}

FInputKey UInputBufferComponent::ConvertFKey(const FKey& FKey)
{
	/*
	 *	Under development, Should be cached once and accessed
	 */
	FInputKey Result;
	UInputSettings* InputSetting = UInputSettings::GetInputSettings();

	TArray<FInputActionKeyMapping> OutMapping;
	InputSetting->GetActionMappingByName("RegisterInput", OutMapping);
	int Max = 0;

	if (InputSetting && (Max = OutMapping.Num()) > 0)
	{
		FString ActionMapControls = TEXT("");
		int Index = 0;
		while (Index < Max) { ActionMapControls.Append(OutMapping[Index].Key.ToString() + TEXT(";")); ++Index; }

		TMap<FString, FInputKey> FKeyToFInputKeyMap;
		int SIndex = 0;
		while (ActionMapControls.FindChar(';', SIndex))
		{
			FString SubStr = TEXT(""); FKeyToFInputKeyMap.Add(SubStr = ActionMapControls.Left(SIndex), ParseKey(SubStr));
			ActionMapControls.RemoveFromStart(SubStr + TEXT(";"));
		}

		const FString KeyPressed = FKey.GetFName().ToString();
		if (FKeyToFInputKeyMap.Find(KeyPressed)) return FKeyToFInputKeyMap[KeyPressed];
	}
	return Result;
}

FInputKey UInputBufferComponent::ParseKey(const FString& SubStr)
{
	return FInputKey();
}
