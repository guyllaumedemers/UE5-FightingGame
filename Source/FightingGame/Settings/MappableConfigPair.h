#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MappableConfigPair.generated.h"

class UPlayerMappableInputConfig;

USTRUCT()
struct FMappableInputConfig
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	TSoftObjectPtr<UPlayerMappableInputConfig> Config;

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	uint8 bClientComponent : 1;

	UPROPERTY(EditAnywhere, Category = "Mappable Input")	// useless for now, we do not handle replication so far
	uint8 bServerComponent : 1;

	FMappableInputConfig()
		: bClientComponent(true)
		, bServerComponent(true)
	{}

	static void RegisterMappableInputConfig(const FMappableInputConfig& InMappableInputConfig);
	static void UnRegisterMappableInputConfig(const FMappableInputConfig& InMappableInputConfig);
};

USTRUCT()
struct FLoadedMappableInputConfig
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, Category = "Mappable Input")
	const UPlayerMappableInputConfig* Config;

	FLoadedMappableInputConfig(const UPlayerMappableInputConfig* InConfig)
		: Config(InConfig)
	{}

	FLoadedMappableInputConfig()
	{}
};
