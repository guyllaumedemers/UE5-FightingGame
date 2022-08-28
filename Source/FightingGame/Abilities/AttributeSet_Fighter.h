#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSet_Fighter.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class FIGHTINGGAME_API UAttributeSet_Fighter : public UAttributeSet
{
	GENERATED_BODY()

	// Begin GameplayAttribute
	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData RageDrive;
	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData Health;
	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData BaseDamage;
	// End GameplayAttribute

protected:

	UAttributeSet_Fighter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};

public:

	ATTRIBUTE_ACCESSORS(ThisClass, RageDrive);
	ATTRIBUTE_ACCESSORS(ThisClass, Health);
	ATTRIBUTE_ACCESSORS(ThisClass, BaseDamage);		// player damage should vary according to the string combo played, combo damage should start from a base damage given by the first action
};
