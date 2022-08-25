#include "FightingCharacter.h"
#include "HealthComponent.h"
#include "FightingGame/Settings/FightingGameUserSettings.h"
#include "FightingGame/Inputs/FightingEnhancedInputComponent.h"

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

		if (const UTaggedInputActionConfig* InputConfig = GameUserSettings->GetInputConfig())
		{
			// thats a very static approach...
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().D_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().D_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().D_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().D_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().Fb_One, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().Fb_Two, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().Fb_Three, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().Fb_Four, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().S_L1, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().S_R1, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().T_L2, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
			EnhancedInputComponent->BindInputAction(InputConfig, FGameplayTags::Get().T_R2, ETriggerEvent::Triggered, EnhancedInputComponent, &UFightingEnhancedInputComponent::CaptureInputActionValue);
		}
	}
}
