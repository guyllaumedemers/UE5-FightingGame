#include "Fighter.h"
#include "HealthComponent.h"
#include "FightingGame/Settings/GameUserSettings_FightingGame.h"
#include "FightingGame/Inputs/EnhancedInputComponent_FightingGame.h"
#include <EnhancedInputSubsystems.h>
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"

AFighter::AFighter(const FObjectInitializer& FObjectInitializer)
	: Super(FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void AFighter::BeginPlay()
{
	Super::BeginPlay();
}

void AFighter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AFighter::PawnClientRestart()
{
	Super::PawnClientRestart();

	ULocalPlayer* LocalPlayer = Cast<APlayerController>(GetController())->GetLocalPlayer();

	check(LocalPlayer);

	const UGameUserSettings_FightingGame* GameUserSettings = UGameUserSettings_FightingGame::Get();

	check(GameUserSettings);

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
}

void AFighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	if (UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(PlayerInputComponent))
	{
		const UGameUserSettings_FightingGame* GameUserSettings = UGameUserSettings_FightingGame::Get();

		check(GameUserSettings);

		const UTaggedInputAction_Config& InputConfig = GameUserSettings->GetInputConfig();

		// thats a very static approach...
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().D_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().D_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().D_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().D_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().Fb_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().Fb_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().Fb_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().Fb_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().S_L1, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().S_R1, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().T_L2, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
		EnhancedInputComponent->BindInputAction(&InputConfig, FNativeGameplayTag_FightingGame::Get().T_R2, ETriggerEvent::Triggered, EnhancedInputComponent, &UEnhancedInputComponent_FightingGame::CaptureInputActionValue);
	}
}
