// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "InteractionnComponent.generated.h"


UCLASS(ClassGroup = "Collision", meta = (DisplayName = "Interaction Collision",BlueprintSpawnableComponent))

class UEPLUGIN_API UInteractionnComponent : public UBoxComponent
{
	GENERATED_BODY()

public:	
	UInteractionnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> InteractMessageClass;*/
	/*UPROPERTY()
	UUserWidget* InteractMessage;*/
	UPROPERTY()
	AActor * ActorToInteract;
	/*UFUNCTION()
	void OnInteractionCompBeginOverlap(AActor* OtherActor);
	UFUNCTION()
	void OnInteractionCompEndOverlap(AActor* OtherActor);
	UFUNCTION(BlueprintCallable)
	void Interact();*/

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
