// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEPlugin : ModuleRules
{
	public UEPlugin(ReadOnlyTargetRules Target) : base(Target)
	{

		PrivateDependencyModuleNames.AddRange(new string[] { "MediaAssets" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","ViewportInteraction", "MediaAssets", "DesktopPlatform","Slate" });
	}
}
