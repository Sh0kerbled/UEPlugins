// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Objective.generated.h"

UENUM()
enum class EObjectiveType : uint8
{
	Location,
	Interact,
	Collect,
	Kill
	};
DECLARE_MULTICAST_DELEGATE_OneParam(FOnObjectiveCompleted, UObjective*);

UCLASS(Abstract)
class PLUGINS_API UObjective : public UObject
{
	GENERATED_BODY()
	
public:
	
	virtual void ActivateObjective(AActor * Character) {}
	
	UPROPERTY(EditAnywhere)
	FText Descrition;
	
	UPROPERTY(VisibleAnywhere)
	EObjectiveType Type;
	
	FOnObjectiveCompleted OnObjectiveCompleted;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsCompleted;
	
	UPROPERTY(VisibleAnywhere)
	bool bCanBeCompleted;
	
};

UCLASS(Abstract)
class PLUGINS_API UInteractionObjective : public UObjective
{
	GENERATED_BODY()

	public:
	    UInteractionObjective();
	
	    void ActivateObjective(AActor * Character) override;
	
	    UPROPERTY(EditAnywhere, meta = (AllowedClasses = "InteractableObject"))
	    AActor* Target;

};

UCLASS()
class PLUGINS_API ULocationObjective : public UObjective
{
	GENERATED_BODY()
	
public:
	
	ULocationObjective();
	void ActivateObjective(AActor * Character) override;

	UPROPERTY(EditAnywhere, meta = (AllowedClasses = "LocationMarker"))
    AActor* Marker;

};