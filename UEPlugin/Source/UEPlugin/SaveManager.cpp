// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "Kismet/GameplayStatics.h"

void USaveManager::Init()
{
	CurrentGameObject = Cast<UTheSaveGame>(UGameplayStatics::CreateSaveGameObject(UTheSaveGame::StaticClass()));
}
bool USaveManager::DoesSaveGameExist(const FString& SlotName)
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}
void USaveManager::LoadGame(const FString& SlotName)
{
	/*CurrentGameObject = UGameplayStatics::LoadGameFromSlot(SlotName, 0);*/
	UGameplayStatics::AsyncLoadGameFromSlot(SlotName, 0, FAsyncLoadGameFromSlotDelegate::CreateUObject(this, &USaveManager::OnGameLoadedFromSlotHandle));

}
void USaveManager::SaveCurrentGame(const FString& SlotName)
{
	UGameplayStatics::SaveGameToSlot(CurrentGameObject, SlotName, 0);
	UGameplayStatics::AsyncSaveGameToSlot(CurrentGameObject, SlotName, 0, FAsyncSaveGameToSlotDelegate::CreateUObject(this, &USaveManager::OnGameSavedToSlotHandle));
}

void USaveManager::OnGameLoadedFromSlotHandle(const FString& SlotName, const int32 UserIndex, USaveGame* SaveGame)
{
	CurrentGameObject = Cast<UTheSaveGame>(SaveGame);
	if (OnGameLoadedFromSlot.IsBound())
	{
		OnGameLoadedFromSlot.Broadcast(SlotName);
	}
}

void USaveManager::OnGameSavedToSlotHandle(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	if (OnGameSavedToSlot.IsBound())
	{
		OnGameSavedToSlot.Broadcast(SlotName);
	}
}

