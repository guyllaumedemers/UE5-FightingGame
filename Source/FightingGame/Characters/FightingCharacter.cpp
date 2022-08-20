#include "FightingCharacter.h"

AFightingCharacter::AFightingCharacter(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{
}

void AFightingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFightingCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
