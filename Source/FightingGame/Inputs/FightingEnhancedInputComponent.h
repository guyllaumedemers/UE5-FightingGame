#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "TaggedInputActionConfig.h"
#include "FightingEnhancedInputComponent.generated.h"

UCLASS()
class FIGHTINGGAME_API UFightingEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

protected:

	UFightingEnhancedInputComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;

public:

	template<typename UserClass, typename FncPtr>
	void BindInputAction(const UTaggedInputActionConfig* InputConfig, FGameplayTag Tag, ETriggerEvent EventTrigger, UserClass* Instigator, FncPtr Delegate);

	// for me -- https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Networking/Actors/RPCs/
	UFUNCTION(Server, Reliable)
	void CaptureInputActionValue(const FInputActionInstance& InputActionInstance);

private:

	UFUNCTION(NetMulticast, Reliable)
	void ProcessInputActionValue(const FInputActionInstance& InputActionInstance);
};

template <typename UserClass, typename FncPtr>
void UFightingEnhancedInputComponent::BindInputAction(const UTaggedInputActionConfig* InputConfig, FGameplayTag Tag, ETriggerEvent EventTrigger, UserClass* Instigator,
	FncPtr Delegate)
{
	check(InputConfig);

	if(const UInputAction* InputAction = InputConfig->FindInputActionByTaggedInput(Tag))
	{
		BindAction(InputAction, EventTrigger, Instigator, Delegate);
	}
}
