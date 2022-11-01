// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionnComponent.h"

#include "InteractableObject.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
UInteractionnComponent::UInteractionnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteractionnComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractionnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

/*void UInteractionnComponent::OnInteractionCompBeginOverlap(AActor* OtherActor)
{
	if (OtherActor->Implements<UInteractableObject>())
	{
		return;
	}
	
	ActorToInteract = OtherActor;
	
	if (InteractMessage == nullptr && InteractMessageClass)
	{
		InteractMessage = CreateWidget<UUserWidget>(GetWorld(),InteractMessageClass);
	}
	
	if (InteractMessage && !InteractMessage->IsInViewport())
	{
		InteractMessage->AddToViewport();
	}
}

void UInteractionnComponent::OnInteractionCompEndOverlap(AActor* OtherActor)
{
	if(ActorToInteract == OtherActor)
	{
		ActorToInteract = nullptr;
		
		if (InteractMessage)
		{
			InteractMessage->RemoveFromViewport();
		}
	}
}

void UInteractionnComponent::Interact()
{
	if(ActorToInteract)
	{
		IInteractableObject::Execute_Interact(ActorToInteract,GetOwner());
	}
}*/

