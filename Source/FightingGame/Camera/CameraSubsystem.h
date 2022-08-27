#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CameraSubsystem.generated.h"

UCLASS()
class FIGHTINGGAME_API UCameraSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:

	UCameraSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
};
