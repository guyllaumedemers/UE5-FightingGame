#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSet_World.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class FIGHTINGGAME_API UAttributeSet_World : public UAttributeSet
{
	GENERATED_BODY()

	// Begin GameplayAttribute
	UPROPERTY(EditDefaultsOnly)
	FGameplayAttributeData Time;
	// End GameplayAttribute

protected:

	UAttributeSet_World(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};

public:

	ATTRIBUTE_ACCESSORS(ThisClass, Time);
};
