// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "FightingSaveGameBase.generated.h"

/*
 *	Dummy Class for CommonUI GetDesiredFocus Override, not necessary in a Fighting game unless I store User Account Data, serialize and upload from here
 *
 *	VERIFY if I can make my inline function const later after implementing the fetching of data from file, low priority
 *
 *	Do Research on how to properly integrate SaveGame Abs Class
 */
UCLASS()
class FIGHTINGGAME_API UFightingSaveGameBase : public USaveGame
{
	GENERATED_BODY()

protected:

	UFightingSaveGameBase(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

public:

	// Will always point at the same PATH, not user define - personal choice
	FORCEINLINE bool HasSaveFile()								{ return IsFileAtPathValid(DirectoryPath); }

	FORCEINLINE FString Load()									{ return LoadFrom(DirectoryPath); }
	FORCEINLINE void Save()										{ SaveAt(DirectoryPath); }

private:

	FORCEINLINE bool IsFileAtPathValid(const FString& PATH)		{ return !GetFileAtPath(PATH).IsEmpty(); }
	FString GetFileAtPath(const FString& PATH);

	FString LoadFrom(const FString&);
	void SaveAt(const FString&);

	// Game Specific
	static const FString DirectoryPath;
};
