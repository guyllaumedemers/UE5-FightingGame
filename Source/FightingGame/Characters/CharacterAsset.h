#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/Texture.h"
#include "CharacterAsset.generated.h"

UCLASS()
class FIGHTINGGAME_API UCharacterAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly);
	FText CharacterFName;;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UTexture> CharacterSelectionIconSmall;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UTexture> CharacterSelectionIconBig;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<USkeletalMesh> CharacterMesh;

public:

	// have to research on how that works...
	UFUNCTION(BlueprintGetter, meta = (ShortTooltip = "Handle localization using FText"))
	FORCEINLINE FText GetFName() const { return CharacterFName; }

	UFUNCTION(BlueprintGetter)
	FORCEINLINE UTexture* GetIconSmall() const { return CharacterSelectionIconSmall.Get(); }

	UFUNCTION(BlueprintGetter)
	FORCEINLINE UTexture* GetIconBig() const { return CharacterSelectionIconBig.Get(); }
	
	// CharacterMesh should not be loaded in memory before being selected and confirmed by players
	// So, mesh should only be loaded by the Asset Manager once the Server Travel to the Transition Stage
	UFUNCTION(BlueprintGetter)
	FORCEINLINE USkeletalMesh* GetMesh() const { return CharacterMesh.Get(); }
};
