#include "MatchSubsystem.h"
#include "FightingGame/Player/Actor_TimerHandler.h"
#include "FightingGame/Abilities/AbilitySystemComponent_FightingGame.h"

void UMatchSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMatchSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UMatchSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	TimerHandler = CreateDefaultSubobject<AActor_TimerHandler>("Timer Handler");
}
