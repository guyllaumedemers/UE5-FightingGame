// Fill out your copyright notice in the Description page of Project Settings.


#include "RaycastAnalyserComponent.h"

URaycastAnalyserComponent::URaycastAnalyserComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bStartWithTickEnabled = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void URaycastAnalyserComponent::SpawnRaycast(const FString& Attachment_SpawnPoint, const FRaycastSpec& RaycastSpec)
{
}
