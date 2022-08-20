#include "HealthComponent.h"
#include "Engine/Engine.h"

UHealthComponent::UHealthComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("HealthComponent GameFeatures Added!"));
	}
}

void UHealthComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
