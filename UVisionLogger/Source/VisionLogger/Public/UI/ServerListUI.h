// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "SlateBasics.h"
#include "MainMenuHUD.h"

// Lays out and controls the Main Menu UI for our tutorial.
class VISIONLOGGER_API SServerListUI : public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SServerListUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
		SLATE_END_ARGS()

	// Constructs and lays out the Main Menu UI Widget.
	// args Arguments structure that contains widget-specific setup information.
	void Construct(const FArguments& args);

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	// Style for the menu
	const struct FGlobalStyle* MenuStyle;

	// Called if "JoinGame" has been clicked
	FReply JoinGameClicked();

	// Called if "FindSession" has been clicked
	FReply FindSessionClicked();

	/**
	Updates the displayed number of found sessions
	@param i - number of sessions
	*/
	void UpdateSessionsString(int i);

	// Default string that shows number of sessions
	FString SessionsString = "Sessions: 0";

	// TAttribute with session text
	TAttribute<FText> Sessions;

	// Getter for sessions text that is used to update UI if it changes 
	FText GetSessions() const;
};