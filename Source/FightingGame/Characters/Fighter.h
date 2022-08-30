#pragma once

#include "CoreMinimal.h"
#include "ModularCharacter.h"
#include "HealthComponent.h"
#include "Fighter.generated.h"

UCLASS()
class FIGHTINGGAME_API AFighter : public AModularCharacter
{
	GENERATED_BODY()

	TObjectPtr<UHealthComponent> HealthComponent;

protected:
	// for me - https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/GameplayArchitecture/Classes/
	AFighter(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PawnClientRestart() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:

	UFUNCTION(BlueprintGetter)
	FORCEINLINE UHealthComponent* GetHealthComponent() const { return HealthComponent.Get(); }
};
