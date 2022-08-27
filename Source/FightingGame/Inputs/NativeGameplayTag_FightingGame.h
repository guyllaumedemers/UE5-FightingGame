#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTag_FightingGame.generated.h"

struct FNativeGameplayTag_FightingGame
{
	static FNativeGameplayTag_FightingGame& Get() { return Singleton; }

	void AddAllTags();

	// annoying to manually declare and handle...
	FGameplayTag D_One;
	FGameplayTag D_Two;
	FGameplayTag D_Three;
	FGameplayTag D_Four;
	FGameplayTag Fb_One;
	FGameplayTag Fb_Two;
	FGameplayTag Fb_Three;
	FGameplayTag Fb_Four;
	FGameplayTag S_L1;
	FGameplayTag T_L2;
	FGameplayTag S_R1;
	FGameplayTag T_R2;

	FNativeGameplayTag_FightingGame()
	{}

private:

	void AddTag(FGameplayTag& OutTag, FName TagName, FString TagComment);

	static FNativeGameplayTag_FightingGame Singleton;
};

class UInputAction;

USTRUCT()
struct FTaggedInputAction_Pair
{
	GENERATED_BODY();

	FGameplayTag GetInputGameplayTag() const { return Input_GameplayTag; }
	const UInputAction* GetInputAction() const { return InputAction; }

	FTaggedInputAction_Pair()
	{}

private:

	UPROPERTY(EditDefaultsOnly);
	const UInputAction* InputAction;

	UPROPERTY(EditDefaultsOnly);
	FGameplayTag Input_GameplayTag;
};
