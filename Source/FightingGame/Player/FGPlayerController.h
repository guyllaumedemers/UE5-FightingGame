// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "GameFramework/PlayerController.h"
#include "FGPlayerController.generated.h"

struct FCheatHandle
{
	FCheatHandle(UCheatManager* const InCheatManager)
		: CheatManagerHandle(InCheatManager)
	{}

	FCheatHandle()
		: CheatManagerHandle(nullptr)
	{}

	~FCheatHandle()
	{
		delete CheatManagerHandle;
	}

	/**
	 *	Cheat Extension State should respond via Delegate calls from Adding, Removing, Enabling, etc...
	 *	from the GameUserSettings.
	 *
	 *	When a LocalPlayer Sets via UI Settings a Cheat Extension State, Enable/Disable
	 *	it's counterpart playercontroller should listen for the state change and trigger the proper callback.
	 */

private:

	UCheatManager* CheatManagerHandle;
};

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API AFGPlayerController : public APlayerController
{
	GENERATED_BODY()

	static FCheatHandle CheatHandle;

public:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
};
