// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Fighter.h"
#include "GameFeaturesSubsystem.h"
#include "HealthComponent.h"
#include "FightingGame/Player/RaycastAnalyserComponent.h"
#include "FightingGame/Combo/ComboAnalyserComponent.h"
#include "FightingGame/Inputs/EnhancedInputComponent_FightingGame.h"
#include "FightingGame/Player/ModularPlayerState.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"

ACharacter_Fighter::ACharacter_Fighter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RaycastAnalyserComponent = CreateDefaultSubobject<URaycastAnalyserComponent>("Raycast Analyser Component");
	ComboAnalyserComponent = CreateDefaultSubobject<UComboAnalyserComponent>("Combo Analyser Component");
	HealthComponent = CreateDefaultSubobject<UHealthComponent>("Health Component");
}

void ACharacter_Fighter::BeginPlay()
{
	Super::BeginPlay();

	if (HealthComponent)
	{
		HealthComponent->OnPawnReady(*GetAbilitySystemComponent());
	}
}

void ACharacter_Fighter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ACharacter_Fighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (IsLocallyControlled() /*probably means the server will never fire &ThisClass::CaptureInput*/)
	{
		UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(PlayerInputComponent);

		check(EnhancedInputComponent);

		const UGameUserSettings_FightingGame* UserSettings = &UGameUserSettings_FightingGame::Get();

		check(UserSettings);

		const FInputConfig_Loaded* OutConfig = &UserSettings->Find(ThisClass::GetClass());

		check(OutConfig);

		const UInputConfig* ThisClassConfig = OutConfig->GetInputConfig();

		check(ThisClassConfig);

		for (const auto& TaggedInputAction_Pair : ThisClassConfig->GetInputAction_Pairs())
		{
			// gameplaytag are only useful when we want to hard reference a unique delegate
			EnhancedInputComponent->BindNativeAction(ThisClassConfig, TaggedInputAction_Pair.GetGameplayTag(), ETriggerEvent::Started, this, &ThisClass::CaptureInput);
		}
	}
}

UAbilitySystemComponent* ACharacter_Fighter::GetAbilitySystemComponent() const
{
	return Cast<AModularPlayerState>(GetPlayerState())->GetAbilitySystemComponent();
}

void ACharacter_Fighter::CaptureInput(const FInputActionInstance& InputActionInstance)
{
	if (IsLocallyControlled() && !ActorHasTag("Ability.Status.Cancelled"))
	{
		// Send signal to Server and trigger animations events if valid

		// While canceled, players cannot fire inputs

		// UComboAnalyserComponent Should append its action list until a combo match is found while firing animation at every new "Combo" Valid - note : the above InputAction is a ComboEntry

		// this need to work with AttributeSet and GAS	
	}
}
