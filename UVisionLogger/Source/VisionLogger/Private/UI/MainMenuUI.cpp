// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#include "MainMenuUI.h"
#include "VisionLogger.h"
#include "GlobalMenuStyle.h" 
#include "MenuStyles.h" 
#include "MultiplayerGI.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuUI::Construct(const FArguments& args)
{
	MainMenuHUD = args._MainMenuHUD;
	MenuStyle = &FMenuStyles::Get().GetWidgetStyle<FGlobalStyle>("Global");

	ChildSlot
		[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Bottom)
		[
	SNew(SVerticalBox)
	+ SVerticalBox::Slot()
		[
			SNew(SEditableTextBox)
			.Style(&MenuStyle->TextBox)
		.Text(FText::FromString("Kitchen"))
		.OnTextChanged_Raw(this, &SMainMenuUI::GetTextFromInput)
		]
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Create Session"))
		.OnClicked(this, &SMainMenuUI::CreateSessionClicked)
		]
	+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.ButtonStyle(&MenuStyle->MenuButtonStyle)
		.TextStyle(&MenuStyle->MenuButtonTextStyle)
		.Text(FText::FromString("Join Session"))
		.OnClicked(this, &SMainMenuUI::JoinSessionClicked)
		]
		]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION


FReply SMainMenuUI::CreateSessionClicked()
{
	if (GEngine) 
	{
		try
		{
			Cast<UMultiplayerGI>(((UGameEngine*)GEngine)->GameInstance)->CreateSessionEvent();
		}
		catch (const std::exception&)
		{

		}
	}
	return FReply::Handled();
}

FReply SMainMenuUI::JoinSessionClicked()
{
	MainMenuHUD->LoadServerList();

	return FReply::Handled();
}

void SMainMenuUI::GetTextFromInput(const FText & Text)
{
	if (GEngine)
	{
		try
		{
			Cast<UMultiplayerGI>(((UGameEngine*)GEngine)->GameInstance)->MapChangeEvent(Text.ToString());
		}
		catch (const std::exception&)
		{

		}
	}
}