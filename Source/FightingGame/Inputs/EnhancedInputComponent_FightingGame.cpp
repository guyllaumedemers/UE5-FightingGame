#include "EnhancedInputComponent_FightingGame.h"
#include "Engine/Engine.h"

UEnhancedInputComponent_FightingGame::UEnhancedInputComponent_FightingGame(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{}

void UEnhancedInputComponent_FightingGame::BeginPlay()
{
	Super::BeginPlay();
	SetIsReplicated(true);
}

void UEnhancedInputComponent_FightingGame::CaptureInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
{
	if (GEngine)
	{
		FString InputInstanceFString = FString::Printf(TEXT("Capturing %s"), *InputActionInstance.GetSourceAction()->GetFName().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, *InputInstanceFString);
	}
	// cover dedicated server and listen server case
	ProcessInputActionValue_Implementation(InputActionInstance);
}

void UEnhancedInputComponent_FightingGame::ProcessInputActionValue_Implementation(const FInputActionInstance& InputActionInstance)
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
