// Fill out your copyright notice in the Description page of Project Settings.

#include "ECSWorld.h"
#include "Systems/TradingSystem.h"
#include "Systems/InventorySystem.h"
#include "Systems/FishingSystem.h"
#include "Systems/TimerSystem.h"
#include "Systems/InputsSystem.h"

// Sets default values
AECSWorld::AECSWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Systems.Add(new TradingSystem());
	m_Systems.Add(new InventorySystem());
	m_Systems.Add(new FishingSystem());
	m_Systems.Add(new TimerSystem());
	m_Systems.Add(new InputsSystem());
}

AECSWorld::~AECSWorld()
{
	for (System* system : m_Systems)
	{
		delete system;
	}
	m_Systems.Empty();
}

// Called every frame
void AECSWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (System* system : m_Systems)
	{
		system->Tick(DeltaTime);
	}
}

void AECSWorld::RegisterActor(AActor* actor)
{
	for (System* system : m_Systems)
	{
		system->TryRegister(actor);
	}
}

void AECSWorld::UnregisterActor(AActor* actor)
{
	for (System* system : m_Systems)
	{
		system->TryUnregister(actor);
	}
}

// Called when the game starts or when spawned
void AECSWorld::BeginPlay()
{
	Super::BeginPlay();
}

