#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FightingGameUserSettings.generated.h"

class UTaggedInputActionConfig;

UCLASS()
class FIGHTINGGAME_API UFightingGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:

	static UFightingGameUserSettings* Get();
	const UTaggedInputActionConfig* GetInputConfig() const;

private:

	TSoftObjectPtr<UTaggedInputActionConfig> TaggedInputActionConfig;
};
