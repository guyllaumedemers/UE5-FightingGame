#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MatchSubsystem.generated.h"

UCLASS()
class FIGHTINGGAME_API UMatchSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	TObjectPtr<AActor> TimerHandler;

protected:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
};
