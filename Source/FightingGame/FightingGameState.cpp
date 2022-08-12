// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingGameState.h"
#include "GameFramework/InputSettings.h"
#include "UObject/ConstructorHelpers.h"
#include "EnhancedInput/Public/InputMappingContext.h"

AFightingGameState::AFightingGameState(const FObjectInitializer& FObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	CanPlayersMove = true;

	const auto AssetFound = ConstructorHelpers::FObjectFinder<UInputMappingContext>(TEXT("/Game/ProjectContent/Inputs/Gameplay/IMC_InputRecord.IMC_InputRecord"));
	if (AssetFound.Succeeded()) DefaultInputMappingContext = AssetFound.Object;
}

void AFightingGameState::BeginPlay()
{
	Super::BeginPlay();

	// Parsing Input Mapping Context, Retrieve all IA and Map to usable Data Collection
	if(DefaultInputMappingContext)
	{
		for(const auto& it : DefaultInputMappingContext->GetMappings())
		{
			FString ActionName = it.Action->GetFName().ToString();
			int SIndex = 0;
			while (ActionName.FindChar('_', SIndex))
			{
				const FString SubStr = ActionName.Left(SIndex);
				ActionName.RemoveFromStart(SubStr + TEXT("_"));
			}
			/*
			 *	TO COMPLETE, Create TMap Values Entry by Parsing IA FName since IA can only Retrieve Engine Built Value, bool - float - vector
			 *	i could use that but... idk... maybe?...
			 *
			 */
			UE_LOG(LogTemp, Error, TEXT("%s"), *it.Key.GetFName().ToString());
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InputMappingContext FAILED TO LOAD FROM REGISTRY"));
	}
}
