// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FightingSaveGameBase.h"
#include "Engine/GameInstance.h"
#include "FightingGameInstance.generated.h"

UCLASS()
class FIGHTINGGAME_API UFightingGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:

	UFightingGameInstance(const FObjectInitializer& FObjectInitializer = FObjectInitializer::Get());

public:

	FORCEINLINE void Save() const				{ if(SaveGameBase) SaveGameBase->Save(); }
	FORCEINLINE void Load()						{ if(SaveGameBase) InitializeGameFromSave(SaveGameBase->Load()); }

	UFUNCTION(BlueprintCallable)
	FORCEINLINE bool HasSave() const			{ return SaveGameBase && SaveGameBase->HasSaveFile(); }

private:

	// Keep track of all file that were locally saved
	TSoftObjectPtr<UFightingSaveGameBase> SaveGameBase;

	void InitializeGameFromSave(const FString&);
};
