// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionTableRow.h"
#include "Components/ActorComponent.h"
#include "InputBufferComponent.generated.h"

UCLASS()
class FIGHTINGGAME_API UInputBufferComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UInputBufferComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:

	// Func Referenced by PlayerController for input Callbacks
	void CaptureInput(const FInputActionInstance&);

	FORCEINLINE void BroadcastInputCapture(const FInputKey& FInputKey) const	{ OnInputCaptureDelEvent.ExecuteIfBound(FInputKey); }
	FORCEINLINE void BroadcastInputStringComplete() const						{ OnInputStringCompleteDelEvent.ExecuteIfBound(); }

	/*
	 *	Research how to Run the Del Binding while keeping things encapsulated inside the Component?
	 *
	 */

private:

	// Del Callback for HUD usage, will display current input captured
	DECLARE_DELEGATE_OneParam(OnInputCaptureDel, FInputKey);
	OnInputCaptureDel OnInputCaptureDelEvent;

	// Del Callback for HUD usage, will erase current input string displayed
	DECLARE_DELEGATE(OnInputStringCompleteDel);
	OnInputStringCompleteDel OnInputStringCompleteDelEvent;

	TArray<FInputKey> InputStack;

	FORCEINLINE bool IsValidKey(const FInputKey& FInputKey) const	{ return FInputKey.KeyHandle != EKeyHandle::None || FInputKey.DirectionalHandle != EDirectionalHandle::None; }
	FORCEINLINE void AddKey(const FInputKey& FInputKey)				{ OnInputCaptureDelEvent.ExecuteIfBound(FInputKey); InputStack.Add(FInputKey); };
	FORCEINLINE void PopKey()										{ InputStack.Pop(); };
	FInputKey GetFInputKey(const FInputActionInstance&) const;
	FORCEINLINE void ClearStack()									{ while (InputStack.Num() > 0) PopKey(); };

	double TimeElapse = 0.f;

	FORCEINLINE bool IsElapseTimeGreater(const double& Value) const								{ return TimeElapse >= Value; };
	FORCEINLINE bool IsLastCaptureTimeGreaterThanMaxThreshold(const FInputKey& FInputKey) const	{ return IsElapseTimeGreater(FInputKey.MaxResetThreshold); };
	FORCEINLINE void ResetInputString()															{ TimeElapse = 0.f; OnInputStringCompleteDelEvent.ExecuteIfBound(); }
};