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

	FORCEINLINE void Clear()
	{
		InputRegistered.Empty();
	}

	DECLARE_DELEGATE_RetVal_OneParam(bool, OnInputActionRegistered, const UInputAction* InAction);
	OnInputActionRegistered OnInputActionRegisteredDel;

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
	}

	FORCEINLINE void Subscribe(const TFunctionRef<bool(const UInputAction*)>& FncPtr)
	{
		OnInputActionRegisteredDel.BindLambda(FncPtr);
	}

	FORCEINLINE void UnSubscribe()
	{
		OnInputActionRegisteredDel.Unbind();
	}

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
