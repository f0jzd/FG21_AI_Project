// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FG21_AI : ModuleRules
{
	public FG21_AI(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay","GameplayTasks","GameplayAbilities","GameplayDebugger" });
	}
}
