#include "ModularEInputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include <InputMappingContext.h>

UModularEInputComponent::UModularEInputComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UModularEInputComponent::OnUnregister()
{
	Super::OnUnregister();
	ClearActionEventBindings();
}

void UModularEInputComponent::OnRegister()
{
	Super::OnRegister();
	ClearActionEventBindings();

	UInputMappingContext* InputMapping = nullptr;
	for (const auto& it : InputMapping->GetMappings())
	{
		BindAction(it.Action, ETriggerEvent::Triggered, this, &ThisClass::CaptureInputActionValue);
	}
}

void UModularEInputComponent::CaptureInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	// cover dedicated server and listen server case
	ProcessInputActionValue_Implementation(InputActionInstance);
}

void UModularEInputComponent::ProcessInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
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
