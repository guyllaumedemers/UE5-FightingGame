#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "ModularEInputComponent.generated.h"

UCLASS()
class FIGHTINGGAME_API UModularEInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

protected:

	UModularEInputComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void OnUnregister() override;
	virtual void OnRegister() override;

private:

	// for me -- https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Networking/Actors/RPCs/
	UFUNCTION(Server, Reliable)
	void CaptureInputActionValue(const FInputActionInstance& InputActionInstance);

	UFUNCTION(NetMulticast, Reliable)
	void ProcessInputActionValue(const FInputActionInstance& InputActionInstance);
};
