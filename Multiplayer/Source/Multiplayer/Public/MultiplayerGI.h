// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Multiplayer.h"
#include "UVisionlogger.h"
#include "MultiplayerGI.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UMultiplayerGI : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent)
	void CreateSessionEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void FindSessionEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void JoinSessionEvent();

	UFUNCTION(BlueprintImplementableEvent)
	void MapChangeEvent(const FString & s);
	
	UPROPERTY(BlueprintReadWrite)
	int NumberOfSessions;

	//TArray<FOnlineSessionSearchResult> SessionsC;

	//FString MapToOpenC = "Kitchen";

	////C++ implementation of the event that is called when the user wants to create a new session
	//void CreateSessionEventC();

	////C++ implementation of the event that is called when the user wants to find an existing session
	//void FindSessionEventC();

	////C++ implementation of the event that is called when the user wants to join the found session
	//void JoinSessionEventC();

	///**
	//C++ implementation of the event that is called when the map the user wants to open changes
	//@param s - Name of the new map to open
	//*/
	//void MapChangeEventC(const FString & s);
};
