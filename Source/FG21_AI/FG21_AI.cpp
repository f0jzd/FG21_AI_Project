// Copyright Epic Games, Inc. All Rights Reserved.

#include "FG21_AI.h"

#include "FGGameplayDebuggerCategory.h"
#include "GameplayDebugger.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, FG21_AI, "FG21_AI" );

void FFG21_AIModule::StartupModule()
{

	IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();

	GameplayDebugger.RegisterCategory("FGCustom", IGameplayDebugger::FOnGetCategory::CreateStatic(&FFGGameplayDebuggerCategory::MakeInstance));
	GameplayDebugger.NotifyCategoriesChanged();


}

void FFG21_AIModule::ShutdownModule()
{
	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();
		GameplayDebugger.UnregisterCategory("FGCustom");
	}



}
