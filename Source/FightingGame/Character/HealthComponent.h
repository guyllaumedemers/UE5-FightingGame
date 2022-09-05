// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class UHealthAttributeSet;

/**
 *
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTINGGAME_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	UHealthAttributeSet* HealthAttributeSet;

public:

	UHealthComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
};
