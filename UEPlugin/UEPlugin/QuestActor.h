// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestActor.generated.h"

UCLASS()
class PLUGINS_API AQuestActor : public AActor
{
	GENERATED_BODY()
	
public:
	
	AQuestActor();

	UPROPERTY(EditAnywhere)
    FText Name;
	
    UPROPERTY(EditAnywhere)
    FText Descrition;
	
    /*UPROPERTY(EditAnywhere)
    TArray<UObjective*> Objectives;*/
	
    UPROPERTY(EditAnywhere)
	bool bIsStoryQuest = true;
	
	UPROPERTY(EditAnywhere)
	bool bKeepObjectivesOrder = true;
	
	UPROPERTY(EditAnywhere)
	AQuestActor* PrerquisedQuest;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsTaken;

	void TakeQuest(AActor * Character);


protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, CallInEditor)
    void UpdateLocation();

	/*void OnObjectiveCompleted(UObjective* Objective);*/

	UFUNCTION(BlueprintCallable, CallInEditor)
    void AddLocationObjective();
	
    UFUNCTION(BlueprintCallable, CallInEditor)
    void AddInteractObjective();


public:	

	virtual void Tick(float DeltaTime) override;
};
