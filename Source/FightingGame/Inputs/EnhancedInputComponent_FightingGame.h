#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "TaggedInputAction_Config.h"
#include "EnhancedInputComponent_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UEnhancedInputComponent_FightingGame : public UEnhancedInputComponent
{
	GENERATED_BODY()

	UFUNCTION(NetMulticast, Reliable)
	void ProcessInputActionValue(const FInputActionInstance& InputActionInstance);

protected:

	UEnhancedInputComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	template<typename UserClass, typename FncPtr>
	void BindInputAction(const UTaggedInputAction_Config* InputConfig, FGameplayTag Tag, ETriggerEvent EventTrigger, UserClass* Instigator, FncPtr Delegate);

	// for me -- https://docs.unrealengine.com/4.26/en-US/InteractiveExperiences/Networking/Actors/RPCs/
	UFUNCTION(Server, Reliable)
	void CaptureInputActionValue(const FInputActionInstance& InputActionInstance);
};

template <typename UserClass, typename FncPtr>
void UEnhancedInputComponent_FightingGame::BindInputAction(const UTaggedInputAction_Config* InputConfig, FGameplayTag Tag, ETriggerEvent EventTrigger, UserClass* Instigator,
	FncPtr Delegate)
{
	check(InputConfig);

	if(const UInputAction* InputAction = InputConfig->FindInputActionByTaggedInput(Tag))
	{
		BindAction(InputAction, EventTrigger, Instigator, Delegate);
	}
}
