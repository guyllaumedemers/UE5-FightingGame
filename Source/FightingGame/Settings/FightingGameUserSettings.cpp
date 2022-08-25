#include "FightingGameUserSettings.h"
#include "Engine/Engine.h"
#include "FightingGame/Inputs/TaggedInputActionConfig.h"

UFightingGameUserSettings* UFightingGameUserSettings::Get()
{
	// make sure to update project settings BEFORE running a CastChecked -- otherwise c++ code will compile but not link properly with GEngine pointing to the base class 
	return GEngine ? CastChecked<ThisClass>(GEngine->GetGameUserSettings()) : nullptr;
}

const UTaggedInputActionConfig* UFightingGameUserSettings::GetInputConfig() const
{
	return TaggedInputActionConfig.Get();
}
