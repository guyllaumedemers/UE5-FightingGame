#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "FightingAssetManager.generated.h"

UCLASS()
class FIGHTINGGAME_API UFightingAssetManager : public UAssetManager
{
	GENERATED_BODY()

private:

	static UObject* SynchronousLoadAsset(const FSoftObjectPath& AssetPath);
	void AddLoadedAsset(const UObject* Asset);

	TSet<const UObject*> LoadedAssets;

	FCriticalSection LoadedAssetsCritical;

public:

	static UFightingAssetManager& Get();

	// force to load the asset at each call?
	template<typename AssetType>
	FORCEINLINE static AssetType* GetAsset(const TSoftObjectPtr<AssetType>& AssetPointer, bool bKeepInMemory = true)
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
};
