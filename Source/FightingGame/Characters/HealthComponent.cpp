#include "HealthComponent.h"
#include "Engine/Engine.h"

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
