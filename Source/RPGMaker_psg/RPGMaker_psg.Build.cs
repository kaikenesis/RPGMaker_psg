// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPGMaker_psg : ModuleRules
{
	public RPGMaker_psg(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(ModuleDirectory);

        PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"EnhancedInput",
			"UMG"
		});
	}
}
