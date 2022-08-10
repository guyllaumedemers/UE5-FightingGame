// Fill out your copyright notice in the Description page of Project Settings.


#include "FightingSaveGameBase.h"

const FString UFightingSaveGameBase::DirectoryPath = TEXT("");

UFightingSaveGameBase::UFightingSaveGameBase(const FObjectInitializer& FObjectInitializer)
{
}

FString UFightingSaveGameBase::GetFileAtPath(const FString& Path)
{
	return FString();
}

FString UFightingSaveGameBase::LoadFrom(const FString& Path)
{
	return FString();
}

void UFightingSaveGameBase::SaveAt(const FString& Path)
{
}
