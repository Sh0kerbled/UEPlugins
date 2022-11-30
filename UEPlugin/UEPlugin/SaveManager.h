// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TheSaveGame.h"
#include "SaveManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameFromSlotAction, const FString&, SlotName);

UCLASS()
class PLUGINS_API USaveManager : public UObject
{
	GENERATED_BODY()
	
public:
	
    void Init();
	
    UFUNCTION(BlueprintCallable)
    bool DoesSaveGameExist(const FString& SlotName);
	
    UFUNCTION(BlueprintCallable)
    void LoadGame(const FString& SlotName);
	
    UFUNCTION(BlueprintCallable)
    void SaveCurrentGame(const FString& SlotName);

	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FOnGameFromSlotAction OnGameLoadedFromSlot;
	
	UPROPERTY(BlueprintReadWrite, BlueprintAssignable)
	FOnGameFromSlotAction OnGameSavedToSlot;
	
protected:
	
    UPROPERTY(BlueprintReadWrite)
    UTheSaveGame * CurrentGameObject;

	void OnGameLoadedFromSlotHandle(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGame);
	
	void OnGameSavedToSlotHandle(const FString& SlotName, const int32 UserIndex, bool bSuccess);
};
