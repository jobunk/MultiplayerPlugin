// Copyright 2018, Institute for Artificial Intelligence - University of Bremen

#include "Multiplayer.h"
#include "MenuStyles.h"

#define LOCTEXT_NAMESPACE "FMultiplayerModule"

void FMultiplayerModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(FMenuStyles::GetStyleSetName());
	FMenuStyles::Initialize();
}

void FMultiplayerModule::ShutdownModule()
{
	FMenuStyles::Shutdown();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMultiplayerModule, Multiplayer)