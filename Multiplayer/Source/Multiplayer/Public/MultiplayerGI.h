// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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
	
	UPROPERTY(BlueprintReadWrite)
	int NumberOfSessions;
};
