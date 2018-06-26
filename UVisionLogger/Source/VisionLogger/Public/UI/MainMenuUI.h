// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"

// Lays out and controls the Main Menu UI for our tutorial.
class VISIONLOGGER_API SMainMenuUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SMainMenuUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

	// Constructs and lays out the Main Menu UI Widget.
	// args Arguments structure that contains widget-specific setup information.
	void Construct(const FArguments& args);

	// Click handler for the Play Game! button – Calls MenuHUD’s PlayGameClicked() event.
	FReply CreateSessionClicked();

	// Click handler for the Quit Game button – Calls MenuHUD’s QuitGameClicked() event.
	FReply JoinSessionClicked();

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	// Style for the menu
	const struct FGlobalStyle* MenuStyle;

	// Handles text changes
	void GetTextFromInput(const FText & Text);
};