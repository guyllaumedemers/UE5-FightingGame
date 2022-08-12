// Fill out your copyright notice in the Description page of Project Settings.


#include "InputActionTableRow.h"

//@TODO Improve the following prototype for better flexibility
//		and cover additional edge cases.
//
FInputKey FInputKey::GetFInputKeyFromAction(const UInputAction* InputAction)
{
	FString InputActionValue = InputAction->GetFName().ToString();
	static const enum class EActionType
	{
		None = 0,
		Action,
		Direction
	};

	EActionType InputActionType = EActionType::None;
	int SIndex = 0;
	while (InputActionValue.FindChar('_', SIndex))
	{
		const FString SubStr = InputActionValue.Left(SIndex);
		// TODO Always Return ActionType::None, fix it
		//		odd...		
		//
		InputActionType = FEnumTool::GetEnumValueFromString<EActionType>("EActionType", SubStr);
		InputActionValue.RemoveFromStart(SubStr + TEXT("_"));
	}
	return [&](const EActionType& ActionType, const FString& StringValue)
	{
		// this is exactly what I wanted to avoid, if we are to add Shoulder Trigger, Joystick triggers, etc not only
		// do we have to extend the enum but also this switch case. Every Header/.cpp file referencing this header will then have to run the pre-processor on this @include to update
		// the translation unit for this .cpp with the updated code and re-compile all translation unit referencing it... bad physical design.
		//
		switch (ActionType)
		{
		case EActionType::Action:
			return FInputKey(FEnumTool::GetEnumValueFromString<EKeyHandle>("EKeyHandle", StringValue), EDirectionalHandle::None);
		case EActionType::Direction:
			return FInputKey(EKeyHandle::None, FEnumTool::GetEnumValueFromString<EDirectionalHandle>("EDirectionalHandle", StringValue));
		default:
			return FInputKey(EKeyHandle::None, EDirectionalHandle::None);
		}
	} (InputActionType, InputActionValue);
}

