// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedInputComponent_FightingGame.h"
#include <EnhancedInputSubsystems.h>
#include "Engine/LocalPlayer.h"
#include "FightingGame/Settings/TaggedPlayerMappableInput_Pair.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"

void UEnhancedInputComponent_FightingGame::BeginPlay()
{
	Super::BeginPlay();
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UEnhancedInputComponent_FightingGame::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UEnhancedInputComponent_FightingGame::OnPossess(const FPlayerMappableInput_Loaded& MappingContext_Pair, APawn* Pawn)
{
	if (Pawn && Pawn->IsLocallyControlled() /*IsLocallyControlled handle Net_Mode check*/)
	{
		APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());

		check(Controller);

		Register(MappingContext_Pair, Controller->GetLocalPlayer());
	}
}

void UEnhancedInputComponent_FightingGame::OnUnPossess(const FPlayerMappableInput_Loaded& MappingContext_Pair, APawn* Pawn)
{
	if (Pawn && Pawn->IsLocallyControlled() /*IsLocallyControlled handle Net_Mode check*/)
	{
		APlayerController* Controller = Cast<APlayerController>(Pawn->GetController());

		check(Controller);

		Unregister(MappingContext_Pair, Controller->GetLocalPlayer());
	}
}

void UEnhancedInputComponent_FightingGame::Register(const FPlayerMappableInput_Loaded& MappingContext_Pair, ULocalPlayer* LocalPlayer)
{
	check(LocalPlayer);

	UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(LocalPlayerSubsystem);

	LocalPlayerSubsystem->AddPlayerMappableConfig(MappingContext_Pair.GetPlayerMappableInput());
}

void UEnhancedInputComponent_FightingGame::Unregister(const FPlayerMappableInput_Loaded& MappingContext_Pair, ULocalPlayer* LocalPlayer)
{
	check(LocalPlayer);

	UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(LocalPlayerSubsystem);

	LocalPlayerSubsystem->RemovePlayerMappableConfig(MappingContext_Pair.GetPlayerMappableInput());
}