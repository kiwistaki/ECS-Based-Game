// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/**
 * 
 */
struct SystemTuple
{
};

struct SystemActorTuple
{
	AActor* m_Actor;
	SystemTuple* m_Tuple;
};

class RESOURCEMANAGER_API System
{
public:
	System();
	virtual ~System();
	void TryRegister(AActor* actor);
	void TryUnregister(AActor* actor);
	void Tick(float deltaTime);
protected:
	virtual bool CanRegister(AActor* actor) const = 0;
	virtual FString GetName() const = 0;
	virtual SystemTuple* CreateTuple(AActor* actor) const = 0;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) {}
private:
	TArray<SystemActorTuple> m_ActorTuples;
};
