// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FightingCharacterBase.generated.h"

class UDataTable;
class UInputBufferComponent;

UCLASS()
class FIGHTINGGAME_API AFightingCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	AFightingCharacterBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void BeginPlay() override;

public:

	// Del Callback Input Capture Handling, disable Input Capture for a period of time
	DECLARE_DELEGATE_OneParam(OnCharacterCancelledDel, double);
	OnCharacterCancelledDel OnCharacterCancelledDelEvent;

	double CancellationTime = 0.f;

	FORCEINLINE TObjectPtr<UInputBufferComponent> GetInputBufferComponent() const		{ return PlayerInputBufferComponent; }
	FORCEINLINE bool GetIsPlayerCancelled() const										{ return IsPlayerCancelled; }
	FORCEINLINE void SetIsPlayerCancelled(const bool& value)							{ IsPlayerCancelled = value; if (value) OnCharacterCancelledDelEvent.ExecuteIfBound(CancellationTime); }

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = InputTable, meta=(AllowedClasses="FInputActionTableRow"));
	TObjectPtr<UDataTable> SharedInputDataTable;

private:

	// Require VisibleAnywhere to show up under RootTransform
	UPROPERTY(VisibleAnywhere);
	TObjectPtr<UInputBufferComponent> PlayerInputBufferComponent;

	bool IsPlayerCancelled = false;
};
