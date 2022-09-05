// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "RaycastAnalyserComponent.generated.h"

/**
 *
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTINGGAME_API URaycastAnalyserComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:

	enum ERaycastSpecType
	{
		Instant,
		Traveling
	};

	struct FRaycastSpec
	{
		FRaycastSpec(const FVector& Dir, int W, int H, int TravelDistance, const ERaycastSpecType& RaycastSpecType)
			: W(W)
			, H(H)
			, Dir(Dir)
			, TravelDistance(TravelDistance)
			, RaycastSpecType(RaycastSpecType)
		{}

		int W;
		int H;
		FVector Dir;
		int TravelDistance;
		ERaycastSpecType RaycastSpecType;
	};

	URaycastAnalyserComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	void SpawnRaycast(const FString& Attachment_SpawnPoint, const FRaycastSpec& RaycastSpec);
};
