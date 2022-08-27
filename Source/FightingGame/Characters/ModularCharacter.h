#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModularCharacter.generated.h"

UCLASS(Abstract)
class FIGHTINGGAME_API AModularCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	AModularCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
