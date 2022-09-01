// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModularCharacter.generated.h"

UCLASS()
class FIGHTINGGAME_API AModularCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	//~AActor INTERFACE
	AModularCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {}
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~AActor INTERFACE
};
