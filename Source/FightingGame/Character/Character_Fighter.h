// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "Character_Fighter.generated.h"

struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API ACharacter_Fighter : public AModularCharacter
{
	GENERATED_BODY()

	// hold health

	// hold collision detection

	// hold combo processing - animation cancelling

	void CaptureInput(const FInputActionInstance& InputActionInstance);

public:

	ACharacter_Fighter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
