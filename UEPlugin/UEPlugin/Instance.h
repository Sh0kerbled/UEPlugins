// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SaveManager.h"
#include "Engine/GameInstance.h"
#include "Instance.generated.h"

/**
 * 
 */
UCLASS()
class PLUGINS_API UInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override;
	
    UPROPERTY(BlueprintReadOnly)
    USaveManager * SaveManager;


};
