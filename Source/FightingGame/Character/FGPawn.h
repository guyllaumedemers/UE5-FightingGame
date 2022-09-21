// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ModularPawn.h"
#include "FGPawn.generated.h"

class UFGHealthComponent;
class UFGHitBoxDetectionComponent;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API AFGPawn : public AModularPawn
{
	GENERATED_BODY()

	TObjectPtr<UFGHitBoxDetectionComponent> HitBoxDetectionComponent;
	TObjectPtr<UFGHealthComponent> HealthComponent;

public:

	AFGPawn(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
