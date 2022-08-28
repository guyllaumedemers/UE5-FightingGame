#include "MatchSubsystem.h"
#include "FightingGame/World/AbilitySystemComponentHandle_World.h"
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
	TimerHandler = CreateDefaultSubobject<AAbilitySystemComponentHandle_World>("Timer Handler");
}
