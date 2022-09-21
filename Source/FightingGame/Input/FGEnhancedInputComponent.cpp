// Fill out your copyright notice in the Description page of Project Settings.


#include "FGEnhancedInputComponent.h"
#include "Engine/LocalPlayer.h"
#include <EnhancedInputSubsystems.h>

void UFGEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UFGEnhancedInputComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UFGEnhancedInputComponent::RegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer)
{
	//TODO Retrieve Hardware Input Bindings stored in Settings from the GameAction_Feature 
	if(ensureAlways(InLocalPlayer))
	{
		UEnhancedInputLocalPlayerSubsystem* const LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(InLocalPlayer);
		LocalPlayerSubsystem->AddPlayerMappableConfig(nullptr);
	}
}

void UFGEnhancedInputComponent::UnRegisterHardwareInputBindings(const ULocalPlayer* const InLocalPlayer)
{
	//TODO Retrieve Hardware Input Bindings stored in Settings from the GameAction_Feature 
	if (ensureAlways(InLocalPlayer))
	{
		UEnhancedInputLocalPlayerSubsystem* const LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(InLocalPlayer);
		LocalPlayerSubsystem->RemovePlayerMappableConfig(nullptr);
	}
}

void UFGEnhancedInputComponent::UnBindNativeAction(const UInputAction* const InInputAction)
{
	if(ensure(InInputAction))
	{
		EnhancedInputActionEventBindings.FindAndRemoveChecked(InInputAction);
	}
}
