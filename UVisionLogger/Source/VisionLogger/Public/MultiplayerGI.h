// Copyright 2017, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "VisionLogger.h"
#include "UVisionlogger.h"
#include "MultiplayerGI.generated.h"

/**
 * 
 */
UCLASS()
class VISIONLOGGER_API UMultiplayerGI : public UGameInstance
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
};
