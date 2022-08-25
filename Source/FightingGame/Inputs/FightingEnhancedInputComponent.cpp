#include "FightingEnhancedInputComponent.h"
#include "Engine/Engine.h"

UFightingEnhancedInputComponent::UFightingEnhancedInputComponent(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UFightingEnhancedInputComponent::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
}

void UFightingEnhancedInputComponent::CaptureInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	if (GEngine)
	{
		FString InputInstanceFString = FString::Printf(TEXT("Capturing %s"), *InputActionInstance.GetSourceAction()->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, *InputInstanceFString);
	}
	// cover dedicated server and listen server case
	ProcessInputActionValue_Implementation(InputActionInstance);
}

void UFightingEnhancedInputComponent::ProcessInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
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
