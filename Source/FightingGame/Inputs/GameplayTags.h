#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayTags.generated.h"

struct FGameplayTags
{
	static FGameplayTags& Get() { return Singleton; }

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

private:

	void AddTag(FGameplayTag& OutTag, FName TagName, FString TagComment);

	static FGameplayTags Singleton;
};

class UInputAction;

USTRUCT()
struct FTaggedInputAction
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	UInputAction* InputAction;

	UPROPERTY(EditAnywhere)
	FGameplayTag GameplayTag;
};
