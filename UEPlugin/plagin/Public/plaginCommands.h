// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "plaginStyle.h"

class FplaginCommands : public TCommands<FplaginCommands>
{
public:

	FplaginCommands()
		: TCommands<FplaginCommands>(TEXT("plagin"), NSLOCTEXT("Contexts", "plagin", "plagin Plugin"), NAME_None, FplaginStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};