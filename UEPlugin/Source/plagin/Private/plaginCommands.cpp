// Copyright Epic Games, Inc. All Rights Reserved.

#include "plaginCommands.h"

#define LOCTEXT_NAMESPACE "FplaginModule"

void FplaginCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "plagin", "Bring up plagin window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
