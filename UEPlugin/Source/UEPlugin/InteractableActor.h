// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableObject.h"
#include "GameFramework/Actor.h"
#include "InteractableActor.generated.h"

UCLASS()
class PLUGINS_API AInteractableActor : public AActor,public IInteractableObject
{
	GENERATED_BODY()
	
public:	

	UFUNCTION(BlueprintCallable)
	void OnInteractionFinished(AActor* ActorInteractedWithObject)
	{
		NotifyInteractionFinished(this, ActorInteractedWithObject);
	}
};
