// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#include "MenuStyles.h"
#include "SlateGameResources.h" 
#include "Multiplayer.h"

TSharedPtr<FSlateStyleSet> FMenuStyles::MenuStyleInstance = NULL;

void FMenuStyles::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FMenuStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

FName FMenuStyles::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyles"));
	return StyleSetName;
}

TSharedRef<FSlateStyleSet> FMenuStyles::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMenuStyles::GetStyleSetName(), "/Multiplayer/UI/Styles", "/Multiplayer/UI/Styles");
	return StyleRef;
}

const ISlateStyle& FMenuStyles::Get()
{
	return *MenuStyleInstance;
}