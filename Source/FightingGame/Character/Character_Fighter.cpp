// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Fighter.h"
#include "Components/SkeletalMeshComponent.h"
#include "FightingGame/Inputs/EnhancedInputComponent_FightingGame.h"

ACharacter_Fighter::ACharacter_Fighter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	USkeletalMeshComponent* SkeletalMeshComponentHandle = nullptr;
	USkeletalMesh* MeshHandle = nullptr;

	/*	
	 *	Setup default here
	 *
	 */
}

void ACharacter_Fighter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(IsLocallyControlled())
	{
		UEnhancedInputComponent_FightingGame* EnhancedInputComponent = Cast<UEnhancedInputComponent_FightingGame>(PlayerInputComponent);

		check(EnhancedInputComponent);

		const UDataAsset_InputConfig* InputConfig = nullptr;

		check(InputConfig);

		for(const auto& TaggedInputAction_Pair : InputConfig->GetInputAction_Pairs())
		{
			EnhancedInputComponent->BindNativeAction(InputConfig, TaggedInputAction_Pair.GetGameplayTag(), ETriggerEvent::Triggered, this, &ThisClass::CaptureInput);
		}
	}
}

void ACharacter_Fighter::CaptureInput(const FInputActionInstance& InputActionInstance)
{
}
