#include "FightingEInputComponent.h"
#include "../Settings/FightingGameUserSettings.h"
#include "PlayerMappableInputConfig.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include <EnhancedInputSubsystems.h>

#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"

UFightingEInputComponent::UFightingEInputComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UFightingEInputComponent::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
}

void UFightingEInputComponent::OnUnregister()
{
	Super::OnUnregister();
	UnRegisterPlayerMappableInputConfigs();
}

void UFightingEInputComponent::OnRegister()
{
	Super::OnRegister();
	RegisterPlayerMappableInputConfig();
}

void UFightingEInputComponent::RegisterPlayerMappableInputConfig()
{
	if (UFightingGameUserSettings* Settings = UFightingGameUserSettings::Get())
	{
		TArray<FLoadedMappableInputConfig> PlayerMappableInputConfigArray = Settings->GetLoadedMappableInputs();
		if (!PlayerMappableInputConfigArray.IsEmpty())
		{
			APlayerController* PC = Cast<APlayerController>(GetOwner());
			UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC ? PC->GetLocalPlayer() : nullptr);

			for (const auto& PlayerMappableInputConfig
				: PlayerMappableInputConfigArray)
			{
				for (const auto& IMC
					: PlayerMappableInputConfig.Config->GetMappingContexts())
				{
					for (const auto& IAction
						: IMC.Key->GetMappings())
					{
						BindAction(IAction.Action, ETriggerEvent::Triggered, this, &ThisClass::CaptureInputActionValue);
					}
					if (InputSystem) InputSystem->AddMappingContext(IMC.Key, 0);
				}
			}
		}
	}
}

void UFightingEInputComponent::UnRegisterPlayerMappableInputConfigs()
{
	ClearActionEventBindings();
}

void UFightingEInputComponent::CaptureInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	if (GEngine)
	{
		FString InputInstanceFString = FString::Printf(TEXT("Capturing %s"), *InputActionInstance.GetSourceAction()->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, *InputInstanceFString);
	}
	// cover dedicated server and listen server case
	ProcessInputActionValue_Implementation(InputActionInstance);
}

void UFightingEInputComponent::ProcessInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	if (GEngine)
	{
		// server
		if (GetOwnerRole() == ROLE_Authority)
		{
			FString InputInstanceFString = FString::Printf(TEXT("Server %s"), *InputActionInstance.GetSourceAction()->GetFName().ToString());
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, *InputInstanceFString);
			return;
		}

		// client
		FString InputInstanceFString = FString::Printf(TEXT("Client %s"), *InputActionInstance.GetSourceAction()->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, *InputInstanceFString);
	}
}
