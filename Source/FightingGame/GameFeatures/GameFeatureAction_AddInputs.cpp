// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureAction_AddInputs.h"
#include "FightingGame/Settings/TaggedPlayerMappableInput_Pair.h"

void UGameFeatureAction_AddInputs::OnGameFeatureRegistering()
{
	Super::OnGameFeatureRegistering();
	for (const auto& InPair : TaggedPlayerMappableInput_Pairs) FTaggedPlayerMappableInput_Pair::Register(InPair);
}

void UGameFeatureAction_AddInputs::OnGameFeatureUnregistering()
{
	Super::OnGameFeatureUnregistering();
	for (const auto& InPair : TaggedPlayerMappableInput_Pairs) FTaggedPlayerMappableInput_Pair::Unregister(InPair);
}

void UGameFeatureAction_AddInputs::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);
	for (const auto& InPair : TaggedPlayerMappableInput_Pairs) FTaggedPlayerMappableInput_Pair::Activate(InPair);
}

void UGameFeatureAction_AddInputs::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);
	for (const auto& InPair : TaggedPlayerMappableInput_Pairs) FTaggedPlayerMappableInput_Pair::Deactivate(InPair);
}

/*
 *	Keep in mind that Hardware inputs are not replicated. Server replication ONLY handle Character movement because of the CharacterMovementComponent
 *	which replicate Character position.
 *
 *	It is not the input itself that travels.
 *
 */