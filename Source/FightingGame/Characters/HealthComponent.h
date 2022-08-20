#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "HealthComponent.generated.h"

UCLASS()
class FIGHTINGGAME_API UHealthComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

protected:

	UHealthComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
