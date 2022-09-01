// Fill out your copyright notice in the Description page of Project Settings.


#include "GameFeatureAction_AddInputs.h"

void UGameFeatureAction_AddInputs::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context)
{
	Super::OnGameFeatureDeactivating(Context);

	// Where should the inputs registered be removed from?
}

void UGameFeatureAction_AddInputs::OnGameFeatureActivating(FGameFeatureActivatingContext& Context)
{
	Super::OnGameFeatureActivating(Context);

	// Where should the inputs registered be stored in?
}

/*
 *	Keep in mind that Hardware inputs are not replicated. Server replication ONLY handle Character movement because of the CharacterMovementComponent
 *	which replicate Character position.
 *
 *	It is not the input itself that travels.
 *
 */