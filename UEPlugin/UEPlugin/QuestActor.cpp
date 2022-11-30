/*
// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestActor.h"

#include "Objective.h"

void AQuestActor::TakeQuest(AActor * Character)
{
	for (int32 i = 0; i < Objectives.Num(); i++)
	{
		if (Objectives[i])
		{
			Objectives[i]->ActivateObjective(Character);
			Objectives[i]->bCanBeCompleted = !bKeepObjectivesOrder || i == 0;
			Objectives[i]->OnObjectiveCompleted.AddUObject(this, &AQuestActor::OnObjectiveCompleted);
		}
	}
	bIsTaken = true;
}

void AQuestActor::OnObjectiveCompleted(UObjective * Objective)
{
	if (bKeepObjectivesOrder)
	{
		int32 ObjectiveIndex;
		if (Objectives.Find(Objective, ObjectiveIndex) &&
		Objectives.IsValidIndex(ObjectiveIndex + 1))
		{
			Objectives[ObjectiveIndex + 1]->bCanBeCompleted = true;
		}
	}
}

void AQuestActor::AddLocationObjective()
{
	Objectives.Add(NewObject<ULocationObjective>(this));
}
void AQuestActor::AddInteractObjective()
{
	Objectives.Add(NewObject<UInteractionObjective>(this));
}
*/

