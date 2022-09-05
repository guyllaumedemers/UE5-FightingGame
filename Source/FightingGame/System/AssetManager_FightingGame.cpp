// Fill out your copyright notice in the Description page of Project Settings.


#include "AssetManager_FightingGame.h"
#include "Engine/Engine.h"
#include "Stats/StatsMisc.h"

//~Static
UAssetManager_FightingGame* UAssetManager_FightingGame::Singleton = nullptr;
//~Static

UAssetManager_FightingGame& UAssetManager_FightingGame::Get()
{
	if (!Singleton)
	{
		Singleton = Cast<ThisClass>(GEngine->AssetManager.Get());
		if (!Singleton) Singleton = NewObject<ThisClass>();
	}
	return *Singleton;
}

void UAssetManager_FightingGame::AddLoadedAsset(const UObject* Asset)
{
	if(ensureAlways(Asset))
	{
		FScopeLock LoadedAssetsLock(&LoadedAssetsCritical /*prevent anyone from accessing/updating the set while the collection is appending*/);
		LoadedAssets.Add(Asset);
	}
}

UObject* UAssetManager_FightingGame::SynchronousLoad(const FSoftObjectPath& AssetPath)
{
	if (AssetPath.IsValid())
	{
		TUniquePtr<FScopeLogTime> LogTimePtr;

		if (IsValid())
		{
			return GetStreamableManager().LoadSynchronous(AssetPath, false);
		}

		return AssetPath.TryLoad();
	}

	return nullptr;
}
