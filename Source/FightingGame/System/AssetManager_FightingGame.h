// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AssetManager_FightingGame.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAME_API UAssetManager_FightingGame : public UAssetManager
{
	GENERATED_BODY()

	static UAssetManager_FightingGame* Singleton;
	FCriticalSection LoadedAssetsCritical;
	TSet<const UObject*> LoadedAssets;

	void AddLoadedAsset(const UObject* Asset);
	UObject* SynchronousLoad(const FSoftObjectPath& AssetPath);

public:

	UAssetManager_FightingGame(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) {};
	static UAssetManager_FightingGame& Get();

	template<typename AssetType>
	AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory = true);
};

template <typename AssetType>
AssetType* UAssetManager_FightingGame::GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory)
{
	const FSoftObjectPath AssetPath = AssetPointer.ToSoftObjectPath();
	AssetType* LoadedAsset = nullptr;

	if (AssetPath.IsValid())
	{
		LoadedAsset = AssetPointer.Get();
		if (!LoadedAsset)
		{
			LoadedAsset = Cast<AssetType>(SynchronousLoad(AssetPath));
			ensureAlwaysMsgf(LoadedAsset, TEXT("Failed to load asset [%s]"), *AssetPointer.ToString());
		}

		if (LoadedAsset && bKeepInMemory)
		{
			Get().AddLoadedAsset(Cast<UObject>(LoadedAsset));
		}
	}
	return LoadedAsset;
}
