#include "AssetManager_FightingGame.h"
#include "Engine/Engine.h"
#include "FightingGame/Inputs/NativeGameplayTag_FightingGame.h"

void UAssetManager_FightingGame::StartInitialLoading()
{
	Super::StartInitialLoading();
	FNativeGameplayTag_FightingGame::Get().AddAllTags();
}

UAssetManager_FightingGame& UAssetManager_FightingGame::Get()
{
	if (GEngine)
	{
		if (UAssetManager_FightingGame* Singleton = Cast<UAssetManager_FightingGame>(GEngine->AssetManager))
		{
			return *Singleton;
		}
	}
	return *NewObject<UAssetManager_FightingGame>();
}

// this callback makes me realize how little control we have over the execution order in unreal. System engine classes
// arent part of an explicit flow defined by devs in production.
UObject* UAssetManager_FightingGame::SynchronousLoadAsset(const FSoftObjectPath& AssetPath)
{
	if (AssetPath.IsValid())
	{
		if (IsValid()) return GetStreamableManager().LoadSynchronous(AssetPath, false);
		return AssetPath.TryLoad();
	}
	return nullptr;
}

void UAssetManager_FightingGame::AddLoadedAsset(const UObject* Asset)
{
	if (Asset)
	{
		FScopeLock LoaddedAssetLock(&LoadedAsset_CriticalSelectionHandle);
		LoadedAssets.Add(Asset);
	}
}
