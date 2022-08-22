#include "FightingEInputComponent.h"
#include "Engine/Engine.h"
#include "PlayerMappableInputConfig.h"
#include "InputMappingContext.h"
#include "../Settings/FightingGameUserSettings.h"

UFightingEInputComponent::UFightingEInputComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UFightingEInputComponent::OnUnregister()
{
	Super::OnUnregister();
	UnRegisterPlayerMappableInputConfigs();
}

void UFightingEInputComponent::OnRegister()
{
	Super::OnRegister();
	if(UFightingGameUserSettings* Settings = UFightingGameUserSettings::Get())
	{
		TArray<FLoadedMappableInputConfig> PlayerMappableInputConfigArray = Settings->GetLoadedMappableInputs();
		if (!PlayerMappableInputConfigArray.IsEmpty())
		{
			for (const auto& PlayerMappableInputConfig
				: PlayerMappableInputConfigArray)
			{
				RegisterPlayerMappableInputConfig(PlayerMappableInputConfig.Config);
			}
			if(GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Yellow, TEXT("Binding Inputs in EInputComponent"));
			}
		}
	}
}

void UFightingEInputComponent::RegisterPlayerMappableInputConfig(const UPlayerMappableInputConfig* PlayerMappableInputEntry)
{
	for(const auto& IMC
		: PlayerMappableInputEntry->GetMappingContexts())
	{
		for (const auto& IAction
			: IMC.Key->GetMappings())
		{
			BindAction(IAction.Action, ETriggerEvent::Triggered, this, &ThisClass::CaptureInputActionValue);
		}
	}
}

void UFightingEInputComponent::UnRegisterPlayerMappableInputConfigs()
{
	ClearActionEventBindings();
}

void UFightingEInputComponent::CaptureInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	FString InputInstanceFString = (TEXT("Capturing %s"), InputActionInstance.GetSourceAction()->GetFName().ToString());
	// cover dedicated server and listen server case
	ProcessInputActionValue_Implementation(InputActionInstance);
}

void UFightingEInputComponent::ProcessInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	// server
	if (GetOwnerRole() == ROLE_Authority)
	{
		FString InputInstanceFString = (TEXT("Server %s"), InputActionInstance.GetSourceAction()->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, *InputInstanceFString);
		return;
	}

	// client
	FString InputInstanceFString = (TEXT("Client %s"), InputActionInstance.GetSourceAction()->GetFName().ToString());
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, *InputInstanceFString);
}
