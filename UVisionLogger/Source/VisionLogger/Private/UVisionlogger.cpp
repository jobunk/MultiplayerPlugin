// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "UVisionLogger.h"
#include "MenuStyles.h"

#define LOCTEXT_NAMESPACE "FUVisionLoggerModule"

void FUVisionLoggerModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(FMenuStyles::GetStyleSetName());
	FMenuStyles::Initialize();
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUVisionLoggerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FMenuStyles::Shutdown();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUVisionLoggerModule, UVisionLogger)