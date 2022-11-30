// Fill out your copyright notice in the Description page of Project Settings.


#include "Instance.h"

#include "SaveManager.h"

/*void UInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance::Init()"));
}*/
void UInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("UMyGameInstance::Init()"));
	
	SaveManager = NewObject<USaveManager>(this);
	SaveManager->Init();
}
