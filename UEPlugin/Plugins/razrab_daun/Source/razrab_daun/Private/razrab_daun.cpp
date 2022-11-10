// Copyright Epic Games, Inc. All Rights Reserved.

#include "razrab_daun.h"
#include "razrab_daunEdMode.h"

#define LOCTEXT_NAMESPACE "Frazrab_daunModule"

void Frazrab_daunModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<Frazrab_daunEdMode>(Frazrab_daunEdMode::EM_razrab_daunEdModeId, LOCTEXT("razrab_daunEdModeName", "razrab_daunEdMode"), FSlateIcon(), true);
}

void Frazrab_daunModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(Frazrab_daunEdMode::EM_razrab_daunEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Frazrab_daunModule, razrab_daun)