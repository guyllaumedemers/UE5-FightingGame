#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UAbilitySystemComponent_FightingGame : public UAbilitySystemComponent
{
	GENERATED_BODY()

	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;

	void UnRegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility);
	void RegisterAbilitySystemComponent_NewAbility(UGameplayAbility* NewAbility);

protected:

	UAbilitySystemComponent_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	template<typename UserClass, typename TypeClass>
	void SetupAbilitySystemComponent_Init(UObject* ASC_Owner);
};

template <typename UserClass, typename TypeClass>
void UAbilitySystemComponent_FightingGame::SetupAbilitySystemComponent_Init(UObject* ASC_Owner)
{
	const UAttributeSet* AttributeSet = GetOrCreateAttributeSubobject(TSubclassOf<UserClass>());

	check(AttributeSet);

	UAbilitySystemComponent* ASC = Cast<IAbilitySystemInterface>(ASC_Owner)->GetAbilitySystemComponent();

	check(ASC);

	FGameplayEffectContextHandle GEContextHandle = ASC->MakeEffectContext();

	if (GEContextHandle.IsValid())
	{
		GEContextHandle.AddSourceObject(ASC_Owner);

		FGameplayEffectSpecHandle GESpecHandle = ASC->MakeOutgoingSpec(TSubclassOf<TypeClass>(), 1, GEContextHandle);

		if(GESpecHandle.IsValid())
		{
			ASC->ApplyGameplayEffectSpecToSelf(*GESpecHandle.Data.Get());
		}
	}
}
