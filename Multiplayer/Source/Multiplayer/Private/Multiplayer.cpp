// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

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