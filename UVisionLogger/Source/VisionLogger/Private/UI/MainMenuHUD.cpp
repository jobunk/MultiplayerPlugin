// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "ServerListUI.h"
#include "UVisionLogger.h"
void AMainMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuUI, SMainMenuUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
	}
	MainMenuUI->SetVisibility(EVisibility::Hidden);
}

void AMainMenuHUD::LoadServerList() 
{
	MainMenuUI->SetVisibility(EVisibility::Hidden);
	SAssignNew(ServerListUI, SServerListUI).MainMenuHUD(this);

	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(ServerListUI.ToSharedRef()));
	}
}

void AMainMenuHUD::GiveSessionsNumber(int i)
{
	ServerListUI->UpdateSessionsString(i);
}

void AMainMenuHUD::MakeVisible()
{
	MainMenuUI->SetVisibility(EVisibility::Visible);
}