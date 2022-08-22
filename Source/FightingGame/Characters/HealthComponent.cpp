#include "HealthComponent.h"
#include "Engine/Engine.h"

UHealthComponent::UHealthComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
