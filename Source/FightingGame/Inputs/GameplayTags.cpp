#include "GameplayTags.h"
#include "GameplayTagsManager.h"

FGameplayTags FGameplayTags::Singleton = FGameplayTags();

void FGameplayTags::AddAllTags()
{
	AddTag(D_One, FName("InputTag.D.One"), TEXT("Directional Down"));
	AddTag(D_Two, FName("InputTag.D.Two"), TEXT("Directional Left"));
	AddTag(D_Three, FName("InputTag.D.Three"), TEXT("Directional Up"));
	AddTag(D_Four, FName("InputTag.D.Four"), TEXT("Directional Right"));
	AddTag(Fb_One, FName("InputTag.Fb.One"), TEXT("FaceButton Down"));
	AddTag(Fb_Two, FName("InputTag.Fb.Two"), TEXT("FaceButton Left"));
	AddTag(Fb_Three, FName("InputTag.Fb.Three"), TEXT("FaceButton Up"));
	AddTag(Fb_Four, FName("InputTag.Fb.Four"), TEXT("FaceButton Right"));
	AddTag(S_L1, FName("InputTag.Shoulder.L1"), TEXT("Shoulder L1"));
	AddTag(S_R1, FName("InputTag.Shoulder.R1"), TEXT("Shoulder R1"));
	AddTag(T_L2, FName("InputTag.Trigger.L2"), TEXT("Trigger L2"));
	AddTag(T_R2, FName("InputTag.Trigger.R2"), TEXT("Trigger R2"));
}

void FGameplayTags::AddTag(FGameplayTag& OutTag, FName TagName, FString TagComment)
{
	OutTag = UGameplayTagsManager::Get().AddNativeGameplayTag(TagName, TagComment);
}
