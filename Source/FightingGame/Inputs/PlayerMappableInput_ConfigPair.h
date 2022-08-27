#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerMappableInput_ConfigPair.generated.h"

class UPlayerMappableInputConfig;

USTRUCT()
struct FPlayerMappableInput_PluginConfig
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	uint8 bClientComponent : 1;

	UPROPERTY(EditAnywhere, Category = "Mappable Input")	// useless for now, we do not handle replication so far
	uint8 bServerComponent : 1;

	static void UnRegisterMappableInputConfig(const FPlayerMappableInput_PluginConfig& InMappableInputConfig);
	static void RegisterMappableInputConfig(const FPlayerMappableInput_PluginConfig& InMappableInputConfig);

	FPlayerMappableInput_PluginConfig()
		: bClientComponent(true)
		, bServerComponent(true)
	{}
};

USTRUCT()
struct FPlayerMappableInput_GameLoadedConfig
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	const UPlayerMappableInputConfig* Config;

	FPlayerMappableInput_GameLoadedConfig(const UPlayerMappableInputConfig* InConfig)
		: Config(InConfig)
	{}

	FPlayerMappableInput_GameLoadedConfig()
	{}
};
