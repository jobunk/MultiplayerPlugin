// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class UVISIONLOGGER_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
	// Initializes the Slate UI and adds it as widget content to the game viewport.
	virtual void PostInitializeComponents() override;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SMainMenuUI> MainMenuUI;

	// Reference to the Main Menu Slate UI.
	TSharedPtr<class SServerListUI> ServerListUI;

public:
	// Load server list
	void LoadServerList();

	/**
	Tells the UI how many sessions have been found
	@param i - number of found sessions
	*/
	UFUNCTION(BlueprintCallable)
	void GiveSessionsNumber(int i);

	// Makes the UI visible
	UFUNCTION(BlueprintCallable)
	void MakeVisible();
};
