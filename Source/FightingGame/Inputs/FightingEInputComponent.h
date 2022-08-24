#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FightingEInputComponent.generated.h"

class UPlayerMappableInputConfig;

UCLASS()
class FIGHTINGGAME_API UFightingEInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

protected:

	UFightingEInputComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void OnUnregister() override;
	virtual void OnRegister() override;

private:

	// for me -- https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Networking/Actors/RPCs/
	UFUNCTION(Server, Reliable)
	void CaptureInputActionValue(const FInputActionInstance& InputActionInstance);

	UFUNCTION(NetMulticast, Reliable)
	void ProcessInputActionValue(const FInputActionInstance& InputActionInstance);

private:
	// passing const pointer - cuz referencing a UDataAsset - instance in memory
	void RegisterPlayerMappableInputConfig();
	void UnRegisterPlayerMappableInputConfigs();
};
