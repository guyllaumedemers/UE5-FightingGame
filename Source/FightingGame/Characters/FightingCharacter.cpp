#include "FightingCharacter.h"
#include "Engine/Engine.h"
#include "HealthComponent.h"
#include "Components/GameFrameworkComponentManager.h"
#include "FightingGame/Inputs/FightingEInputComponent.h"

AFightingCharacter::AFightingCharacter(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void AFightingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFightingCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}