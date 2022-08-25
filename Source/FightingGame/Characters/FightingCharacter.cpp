#include "FightingCharacter.h"
#include "HealthComponent.h"
#include "FightingGame/Settings/FightingGameUserSettings.h"
#include "FightingGame/Inputs/FightingEnhancedInputComponent.h"
#include <EnhancedInputSubsystems.h>
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"

AFightingCharacter::AFightingCharacter(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void AFightingCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AFightingCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AFightingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	if (UFightingEnhancedInputComponent* EnhancedInputComponent = Cast<UFightingEnhancedInputComponent>(PlayerInputComponent))
	{
		const UFightingGameUserSettings* GameUserSettings = UFightingGameUserSettings::Get();

		check(GameUserSettings);

		ULocalPlayer* LocalPlayer = Cast<APlayerController>(GetController())->GetLocalPlayer();

		check(LocalPlayer);

		// like im getting the PMI here for Input binding to hardware inputs which can load multiple assets...
		// some might not even be usefull at first... what if there is pickup interaction like smash bros? Press X could Jab Hit && Pickup Object?
		// how would priority be handles?
		if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
		{
			for (const auto& PlayerMappableInputConfig : GameUserSettings->GetPlayerMappableInputConfigs())
			{
				EnhancedInputLocalPlayerSubsystem->AddPlayerMappableConfig(PlayerMappableInputConfig.Get());
			}
		}

		const UTaggedInputActionConfig& InputConfig = GameUserSettings->GetInputConfig();

		// thats a very static approach...
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().D_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().D_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().D_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().D_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().Fb_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().Fb_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().Fb_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().Fb_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().S_L1, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().S_R1, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().T_L2, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FGameplayTags::Get().T_R2, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
	}
}
