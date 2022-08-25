#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FightingAssetManager.generated.h"

UCLASS()
class FIGHTINGGAME_API UFightingAssetManager : public UAssetManager
{
	GENERATED_BODY()

protected:

	virtual void StartInitialLoading() override;

public:

	static UFightingAssetManager& Get();

	template<typename AssetType>
	static AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory = true);

private:

	static UObject* SynchronousLoadAsset(const FSoftObjectPath& AssetPath);
	void AddLoadedAsset(const UObject* Asset);

	FCriticalSection LoadedAssetsCritical;
	TSet<const UObject*> LoadedAssets;
};

template <typename AssetType>
AssetType* UFightingAssetManager::GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory)
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
