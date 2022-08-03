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
			const FString SubStr = ActionMapControls.Left(SIndex);

			FKeyToFInputKeyMap.Add(SubStr, ParseKey(SubStr));
			ActionMapControls.RemoveFromStart(SubStr + TEXT(";"));
		}

		const FString KeyPressed = FKey.GetFName().ToString();
		if (FKeyToFInputKeyMap.Find(KeyPressed)) return FKeyToFInputKeyMap[KeyPressed];
	}
	return Result;
}

FInputKey UInputBufferComponent::ParseKey(FString SubStr)
{
	// DefaultInput.ini

	// Key = Gamepad_DPad_Up
	// Key = Gamepad_DPad_Down
	// Key = Gamepad_DPad_Right
	// Key = Gamepad_DPad_Left
	// Key = Gamepad_FaceButton_Bottom
	// Key = Gamepad_FaceButton_Right
	// Key = Gamepad_FaceButton_Left
	// Key = Gamepad_FaceButton_Top
	// Key = Gamepad_LeftShoulder
	// Key = Gamepad_LeftTrigger
	// Key = Gamepad_RightShoulder
	// Key = Gamepad_RightTrigger

	FInputKey Result;

	FString ControllerFName = TEXT("");
	FString ControllerActionType = TEXT("");
	FString ControllerActionValue = TEXT("");

	int SIndex = 0;
	while (SubStr.FindChar('_', SIndex))
	{
		const FString ParseResult = SubStr.Left(SIndex);
		if (ControllerFName.IsEmpty()) ControllerFName = ParseResult;
		else if (ControllerActionType.IsEmpty()) ControllerActionType = ParseResult;
		SubStr.RemoveFromStart(ParseResult + TEXT("_"));
	}
	/*
	 *	Don't really like this, what if we had more complex Input String. Example: Vive_Right_Trigger_Axis
	 *	Input Parsing should always be: {ControllerType}, {ControllerActionType}, {ControllerActionValue}
	 *
	 *	Maybe I should parse searching for Cap letters? To think on...
	 */
	if (ControllerActionType.IsEmpty()) ControllerActionType = SubStr;
	else ControllerActionType = SubStr;
	return Result;
}
