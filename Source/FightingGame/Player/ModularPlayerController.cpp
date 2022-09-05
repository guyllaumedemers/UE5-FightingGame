// Fill out your copyright notice in the Description page of Project Settings.


#include "ModularPlayerController.h"
#include <Components/GameFrameworkComponentManager.h>
#include "Engine/World.h"
#include "FightingGame/GameModes/ModularGameState.h"
#include "FightingGame/Inputs/EnhancedInputComponent_FightingGame.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"

void AModularPlayerController::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AModularPlayerController::BeginPlay()
{
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);
	Super::BeginPlay();
}

void AModularPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);
	Super::EndPlay(EndPlayReason);
}

void AModularPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(IsLocalController())
	{
		UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(InputComponent);

		check(EnhancedInputComponent);

		const AModularGameState* GameState = Cast<AModularGameState>(GetWorld()->GetGameState());

		check(GameState);

		TArray<FGameplayTag> TagArrayHandle;

		GameState->GetGameplayTagContainer().GetGameplayTagArray(TagArrayHandle);

		ensureMsgf(!TagArrayHandle.IsEmpty(), TEXT("Game State doesn't have GameplayTags set in the current Experience"));

		for (const auto& InTag : TagArrayHandle)
		{
			const FPlayerMappableInput_Loaded& ActiveExperienceInput = UGameUserSettings_FightingGame::Get().Find(InTag);
			EnhancedInputComponent->OnPossess(ActiveExperienceInput, InPawn);
		}
	}
}

void AModularPlayerController::OnUnPossess()
{
	if (IsLocalController())
	{
		UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(InputComponent);

		check(EnhancedInputComponent);

		const AModularGameState* GameState = Cast<AModularGameState>(GetWorld()->GetGameState());

		check(GameState);

		TArray<FGameplayTag> TagArrayHandle;

		GameState->GetGameplayTagContainer().GetGameplayTagArray(TagArrayHandle);

		for (const auto& InTag : TagArrayHandle)
		{
			const FPlayerMappableInput_Loaded& ActiveExperienceInput = UGameUserSettings_FightingGame::Get().Find(InTag);
			EnhancedInputComponent->OnUnPossess(ActiveExperienceInput, GetPawn());
		}
	}
	Super::OnUnPossess();
}