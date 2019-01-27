// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSRegistrationComponent.h"
#include "EngineUtils.h"
#include "ECS/ECSWorld.h"

// Sets default values for this component's properties
UECSRegistrationComponent::UECSRegistrationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UECSRegistrationComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AECSWorld> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		actorItr->RegisterActor(GetOwner());
		break;
	}
}


// Called every frame
void UECSRegistrationComponent::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	for (TActorIterator<AECSWorld> actorItr(GetWorld()); actorItr; ++actorItr)
	{
		actorItr->UnregisterActor(GetOwner());
		break;
	}
}

