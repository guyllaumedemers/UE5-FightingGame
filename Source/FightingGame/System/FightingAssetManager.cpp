#include "FightingAssetManager.h"
#include "Engine/Engine.h"
#include "FightingGame/Inputs/GameplayTags.h"

void UFightingAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FGameplayTags::Get().AddAllTags();
}

UFightingAssetManager& UFightingAssetManager::Get()
{
	if (GEngine)
	{
		if (UFightingAssetManager* Singleton = Cast<UFightingAssetManager>(GEngine->AssetManager))
		{
			return *Singleton;
		}
	}
	return *NewObject<UFightingAssetManager>();
}

// this callback makes me realize how little control we have over the execution order in unreal. System engine classes
// arent part of an explicit flow defined by devs in production.
UObject* UFightingAssetManager::SynchronousLoadAsset(const FSoftObjectPath& AssetPath)
{
	if (AssetPath.IsValid())
	{
		if (IsValid()) return GetStreamableManager().LoadSynchronous(AssetPath, false);
		return AssetPath.TryLoad();
	}
	return nullptr;
}

void UFightingAssetManager::AddLoadedAsset(const UObject* Asset)
{
	if (Asset)
	{
		FScopeLock LoaddedAssetLock(&LoadedAssetsCritical);
		LoadedAssets.Add(Asset);
	}
}
