// Fill out your copyright notice in the Description page of Project Settings.

#include "System.h"

System::System()
{
}

System::~System()
{
}

void System::TryRegister(AActor* actor)
{
	if (CanRegister(actor))
	{
		SystemActorTuple actorTuple;
		actorTuple.m_Actor = actor;
		actorTuple.m_Tuple = CreateTuple(actor);
		m_ActorTuples.Add(actorTuple);

		FString name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("Registering %s to %s system"), *actor->GetName(), *name);
	}
}

void System::TryUnregister(AActor* actor)
{
	for (int i = 0; i < m_ActorTuples.Num(); ++i)
	{
		if (m_ActorTuples[i].m_Actor == actor)
		{
			delete m_ActorTuples[i].m_Tuple;
			m_ActorTuples.RemoveAt(i);

			FString name = GetName();
			UE_LOG(LogTemp, Warning, TEXT("Unregistering %s to %s system"), *actor->GetName(), *name);
			break;
		}
	}
}

void System::Tick(float deltaTime)
{
	for (SystemActorTuple& actorTuple : m_ActorTuples)
	{
		TickTuple(actorTuple.m_Tuple, deltaTime);
	}
}