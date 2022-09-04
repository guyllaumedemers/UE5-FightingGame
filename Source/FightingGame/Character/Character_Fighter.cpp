// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Fighter.h"
#include "FightingGame/Inputs/EnhancedInputComponent_FightingGame.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"

ACharacter_Fighter::ACharacter_Fighter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ACharacter_Fighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(IsLocallyControlled())
	{
		UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(PlayerInputComponent);

		check(EnhancedInputComponent);

		const UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		const FInputConfig_Loaded* OutConfig = &UserSettings->Find(ThisClass::StaticClass());

		check(OutConfig);

		const UInputConfig* ThisClassConfig = OutConfig->GetInputConfig();

		check(ThisClassConfig);

		for(const auto& TaggedInputAction_Pair : ThisClassConfig->GetInputAction_Pairs())
		{
			EnhancedInputComponent->BindNativeAction(ThisClassConfig, TaggedInputAction_Pair.GetGameplayTag(), ETriggerEvent::Triggered, this, &ThisClass::CaptureInput);
		}
	}
}

void ACharacter_Fighter::CaptureInput(const FInputActionInstance& InputActionInstance)
{
}
