// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "ModularCharacter.h"
#include "Character_Fighter.generated.h"

class URaycastAnalyserComponent;
class UComboAnalyserComponent;
class UHealthComponent;
struct FInputActionInstance;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API ACharacter_Fighter : public AModularCharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URaycastAnalyserComponent> RaycastAnalyserComponent;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UComboAnalyserComponent> ComboAnalyserComponent;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHealthComponent> HealthComponent;

	void CaptureInput(const FInputActionInstance& InputActionInstance);

public:

	ACharacter_Fighter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
