// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FightingGame/Combo/Combo.h"
#include "PrimaryDataAsset_Character.generated.h"

class USkeletalMesh;
class UTexture2D;

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UPrimaryDataAsset_Character : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly)
	TArray<FCombo> Combos;

	UPROPERTY(EditDefaultsOnly)
	FName CName;

public:

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
