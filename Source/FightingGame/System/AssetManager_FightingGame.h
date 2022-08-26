#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "AssetManager_FightingGame.generated.h"

UCLASS()
class FIGHTINGGAME_API UAssetManager_FightingGame : public UAssetManager
{
	GENERATED_BODY()

protected:

	virtual void StartInitialLoading() override;

public:

	static UAssetManager_FightingGame& Get();

	template<typename AssetType>
	static AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory = true);

private:

	static UObject* SynchronousLoadAsset(const FSoftObjectPath& AssetPath);
	void AddLoadedAsset(const UObject* Asset);

	FCriticalSection LoadedAsset_CriticalSelectionHandle;
	TSet<const UObject*> LoadedAssets;
};

template <typename AssetType>
AssetType* UAssetManager_FightingGame::GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory)
{
	AssetType* LoadedAsset = nullptr;

	const FSoftObjectPath AssetPath = AssetPointer.ToSoftObjectPath();
	if (AssetPath.IsValid())
	{
		LoadedAsset = AssetPointer.Get();
		if (!LoadedAsset)
		{
			LoadedAsset = Cast<AssetType>(SynchronousLoadAsset(AssetPath));
		}
		if (LoadedAsset && bKeepInMemory)
		{
			Get().AddLoadedAsset(Cast<UObject>(LoadedAsset));
		}
	}
	return LoadedAsset;
}
