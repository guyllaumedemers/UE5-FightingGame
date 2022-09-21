// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "FGInputActionPair.h"
#include "GameplayTagContainer.h"
#include "FGEnhancedInputComponent.generated.h"

class ULocalPlayer;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UFGEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

	TMap<const UInputAction*, FEnhancedInputActionValueBinding> EnhancedInputActionEventBindings; /*Unsafe, can be garbage collected*/

public:

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	void RegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer);
	void UnRegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer);

public:

	template<typename UserClass, typename FncPtr>
	void BindNativeAction(const UFGPawnInputConfig* InInputConfig, const FGameplayTag& InGameplayTag, ETriggerEvent InTriggerEvent, UserClass* InOwner, FncPtr InDelegate);

	void UnBindNativeAction(const UInputAction* const InInputAction);
};

template <typename UserClass, typename FncPtr>
void UFGEnhancedInputComponent::BindNativeAction(const UFGPawnInputConfig* InInputConfig, const FGameplayTag& InGameplayTag, ETriggerEvent InTriggerEvent,
	UserClass* InOwner, FncPtr InDelegate)
{
	if(ensure(InInputConfig))
	{
		const UInputAction* const OutInputAction = InInputConfig->Find(InGameplayTag);
		if(ensure(OutInputAction))
		{
			const FEnhancedInputActionEventBinding& EnhancedInputActionEventBinding = BindAction(OutInputAction, InTriggerEvent, InOwner, InDelegate);
			//EnhancedInputActionEventBindings.FindOrAdd(OutInputAction, EnhancedInputActionEventBinding);
		}
	}
}
