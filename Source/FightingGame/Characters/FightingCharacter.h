// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "FightingCharacter.generated.h"

class UHealthComponent;

UCLASS()
class FIGHTINGGAME_API AFightingCharacter : public AModularCharacter
{
	GENERATED_BODY()

protected:
	// for me - https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/GameplayArchitecture/Classes/
	AFightingCharacter(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:

	TObjectPtr<UHealthComponent> HealthComponent;
};
