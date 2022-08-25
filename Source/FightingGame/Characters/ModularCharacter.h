#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModularCharacter.generated.h"

class UTaggedInputActionConfig;

UCLASS(Abstract)
class FIGHTINGGAME_API AModularCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
