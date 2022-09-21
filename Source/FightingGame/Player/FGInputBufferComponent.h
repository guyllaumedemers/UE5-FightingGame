// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FGInputBufferComponent.generated.h"

class UInputAction;

/**
 *
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTINGGAME_API UFGInputBufferComponent : public UActorComponent
{
	GENERATED_BODY()

	TArray<const UInputAction*> InputRegistered;

	FTimerHandle TimerHandle;

	DECLARE_DELEGATE_RetVal_OneParam(bool, OnInputActionRegistered, const UInputAction* InAction);
	OnInputActionRegistered OnInputActionRegisteredDel;

	DECLARE_DELEGATE_OneParam(OnInputActionStackConsumed, const TArray<const UInputAction*>& InActionStack);
	OnInputActionStackConsumed OnInputActionStackConsumedDel;

	FORCEINLINE void Clear()
	{
		bool Result =
			OnInputActionStackConsumedDel.ExecuteIfBound(InputRegistered);
		if(!Result)
		{
			UE_LOG(LogTemp, Error, TEXT("OnInputActionStackConsumedDel Invalid, Require a Subscriber!"));
		}
		InputRegistered.Empty();
	}

public:

	FORCEINLINE void Add(const UInputAction* InAction)
	{
		bool Result =
			OnInputActionRegisteredDel.IsBound() &&
			OnInputActionRegisteredDel.Execute(InAction);

		if(Result)
		{
			InputRegistered.Add(InAction);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Actor Input Action Perform Failed!"));
			Clear();
		}
	}

	FORCEINLINE void SubscribeOnInputActionRegistered(const TFunctionRef<bool(const UInputAction*)>& FncPtr)
	{
		OnInputActionRegisteredDel.BindLambda(FncPtr);
	}

	FORCEINLINE void UnSubscribeOnInputActionRegistered()
	{
		OnInputActionRegisteredDel.Unbind();
	}

	FORCEINLINE void SubscribeOnInputActionStackConsumed(const TFunctionRef<void(const TArray<const UInputAction*>&)>& FncPtr)
	{
		OnInputActionStackConsumedDel.BindLambda(FncPtr);
	}

	FORCEINLINE void UnSubscribeOnInputActionStackConsumed()
	{
		OnInputActionStackConsumedDel.Unbind();
	}

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
