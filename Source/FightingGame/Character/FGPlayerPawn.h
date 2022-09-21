// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FGPawn.h"
#include "InputAction.h"
#include "FGPlayerPawn.generated.h"

class UFGInputBufferComponent;
class UFGComboParserComponent;

UCLASS()
class FIGHTINGGAME_API AFGPlayerPawn : public AFGPawn
{
	GENERATED_BODY()

	TObjectPtr<UFGInputBufferComponent> InputBufferComponent; /*APawn could have an Input Buffer Component or a PlayerController could have one, would be more efficient if in a tag team environment if PC was the Holder but would require redesign*/
	TObjectPtr<UFGComboParserComponent> ComboParserComponent;

public:

	AFGPlayerPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void OnPosses() override;
	virtual void OnUnPossess() override;

public:

	void OnCapture(const FInputActionInstance& InputActionInstance);
};
