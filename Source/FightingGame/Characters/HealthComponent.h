#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "HealthComponent.generated.h"

USTRUCT()
struct FHealthStateAttribute
{
	GENERATED_BODY();

	FHealthStateAttribute()
		: bIsImmutable(false)
	{}

	FORCEINLINE bool IsImmutable() const			{ return bIsImmutable; }
	FORCEINLINE void IsImmutable(const bool& Value) { bIsImmutable = Value; }

private:

	bool bIsImmutable;
};

USTRUCT()
struct FHealthAttribute
{
	GENERATED_BODY();

	FHealthAttribute(float CurrentHealth, float MaxHealth)
		: CurrentHealth(CurrentHealth)
		, MaxHealth(MaxHealth)
	{}

	FHealthAttribute()
		: CurrentHealth(0.f)
		, MaxHealth(100.f)
	{}

	DECLARE_DELEGATE_TwoParams(OnHealthAttributeChanged, float Modifier, AActor* ATarget);
	OnHealthAttributeChanged OnHealthAttributeChangedEvent;

	DECLARE_DELEGATE_OneParam(OnHealthAttributeDeathTriggered, AActor*);
	OnHealthAttributeDeathTriggered OnHealthAttributeDeathTriggeredEvent;

	FORCEINLINE float GetCurrentHealth() const				{ return CurrentHealth; }
	FORCEINLINE void SetCurrentHealth(const float& Value)	{ CurrentHealth = Value; }
	FORCEINLINE void ResetCurrentHealth()					{ CurrentHealth = MaxHealth; }

private:

	float CurrentHealth;
	float MaxHealth;

	// OnHealthAttributeChanged process and notify according to the delegates below to commonUI which perform an animation for the health bar.

	DECLARE_DELEGATE_ThreeParams(OnHealthAttributeGain, float Current, float Modifier, AActor* ATarget);
	OnHealthAttributeGain OnHealthAttributeGainEvent;

	DECLARE_DELEGATE_ThreeParams(OnHealthAttributeLost, float Current, float Modifier, AActor* ATarget);
	OnHealthAttributeLost OnHealthAttributeLostEvent;
};

UCLASS()
class FIGHTINGGAME_API UHealthComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

protected:

	UHealthComponent(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	FORCEINLINE bool GetHealthState() const					{ return HealthStateAttribute.IsImmutable(); }
	FORCEINLINE void SetHealthState(const bool& Value)		{ HealthStateAttribute.IsImmutable(Value); }

	FORCEINLINE float GetHealth() const				{ return HealthAttribute.GetCurrentHealth(); }
	FORCEINLINE void SetHealth(const float& Value)	{ HealthAttribute.SetCurrentHealth(Value); }

private:

	FHealthStateAttribute HealthStateAttribute;
	FHealthAttribute HealthAttribute;
};
