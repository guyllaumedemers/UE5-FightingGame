// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "InputActionTableRow.generated.h"

struct FEnumTool
{
	template <typename EnumType>
	static FORCEINLINE EnumType GetEnumValueFromString(const FString& EnumName, const FString& String) {
		const UEnum* Enum = FindObject<UEnum>(ANY_PACKAGE, *EnumName, true);
		if (!Enum) {
			return EnumType(0);
		}
		return (EnumType)Enum->GetIndexByName(FName(*String));
	}

	template<typename TEnum>
	static FORCEINLINE FString GetEnumValueAsString(const FString& Name, TEnum Value) {
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
		if (!EnumPtr) {
			return FString("Invalid");
		}
		return EnumPtr->GetNameByValue((int64)Value).ToString();
	}
};

/*
 *	Enum make sense here as there will never be more values than the ones declared below.
 *	Possible combinations are covered using bitmask Flags which is more than enough for creating complex combo strings.
 *
 */

UENUM(BlueprintType, Flags)
enum class EKeyHandle : uint8
{
	None = 0,
	One = 1 << 0,
	Two = 1 << 1,
	Three = 1 << 2,
	Four = 1 << 3,
};
ENUM_CLASS_FLAGS(EKeyHandle);

UENUM(BlueprintType, Flags)
enum class EDirectionalHandle : uint8
{
	None = 0,
	F = 1 << 0,
	U = 1 << 1,
	D = 1 << 2,
	B = 1 << 3,
};
ENUM_CLASS_FLAGS(EDirectionalHandle);

class UInputAction;

USTRUCT(BlueprintType)
struct FInputKey
{
	GENERATED_BODY();

	FInputKey() : KeyHandle(EKeyHandle::None), DirectionalHandle(EDirectionalHandle::None), MinResetThreshold(0.f), MaxResetThreshold(0.f)
	{}

	FInputKey(const EKeyHandle& KeyHandle, const EDirectionalHandle& DirectionalHandle) : KeyHandle(KeyHandle), DirectionalHandle(DirectionalHandle)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = EKeyHandle, ShortTooltip = "Bitmask for 1,2,3,4 Combination"));
	EKeyHandle KeyHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Bitmask, BitmaskEnum = EDirectionalHandle, ShortTooltip = "Bitmask for F,U,D,B Combination"));
	EDirectionalHandle DirectionalHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShortTooltip = "Frame Perfect Execution"));
	float MinResetThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ShortTooltip = "Max Frame Execution Possible"));
	float MaxResetThreshold;

	FORCEINLINE static FInputKey Create(const UInputAction* InputAction) { return GetFInputKeyFromAction(InputAction); };

private:

	static FInputKey GetFInputKeyFromAction(const UInputAction*);
};

USTRUCT(BlueprintType)
struct FInputString
{
	GENERATED_BODY();

	FInputString() : Sequence(TArray<FInputKey>())
	{}

	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	TArray<FInputKey> Sequence;
};

USTRUCT(BlueprintType)
struct FInputActionTableRow : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	FInputString Combo;
};
