// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGameState.h"
#include "GameFramework/InputSettings.h"

AFightingGameState::AFightingGameState(const FObjectInitializer& FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	CanPlayersMove = true;
}

void AFightingGameState::BeginPlay()
{
	Super::BeginPlay();
	RegisterInputs();
	for (auto it : UEInputToCustomKeyMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(it.Key));
	}
}

void AFightingGameState::RegisterInputs()
{
	UInputSettings* InputSetting = UInputSettings::GetInputSettings();

	if (InputSetting)
	{
		TArray<FInputActionKeyMapping> OutMapping;
		InputSetting->GetActionMappingByName("RegisterInput", OutMapping);
		int Max = 0;

		if ((Max = OutMapping.Num()) > 0)
		{
			FString ActionMapControls = TEXT("");
			int Index = 0;
			while (Index < Max) { ActionMapControls.Append(OutMapping[Index].Key.ToString() + TEXT(";")); ++Index; }
			
			int SIndex = 0;
			while (ActionMapControls.FindChar(';', SIndex))
			{
				const FString SubStr = ActionMapControls.Left(SIndex);

				this->UEInputToCustomKeyMap.Add(SubStr, ParseKey(SubStr));
				ActionMapControls.RemoveFromStart(SubStr + TEXT(";"));
			}
		}
	}
}

FInputKey AFightingGameState::ParseKey(FString SubStr)
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
	/*
	 *	Incomplete Require FInput assignment for each Key Entry, basically we need to parse the above string and retrieve it's ControllerActionType to
	 *	determine if it's a directional input or a face button
	 *	
	 *	then, assign the ControllerActionValue
	 *
	 */
	return Result;
}
