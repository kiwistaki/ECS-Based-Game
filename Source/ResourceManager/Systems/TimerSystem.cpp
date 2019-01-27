// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerSystem.h"

TimerSystem::TimerSystem()
{
}

TimerSystem::~TimerSystem()
{
}

bool TimerSystem::CanRegister(AActor* actor) const
{
	return actor->GetComponentByClass(UTimerComponent::StaticClass()) != nullptr;
}

SystemTuple* TimerSystem::CreateTuple(AActor* actor) const
{
	TimerSystemTuple* tuple = new TimerSystemTuple;
	tuple->m_TimerComponent = Cast<UTimerComponent>(actor->GetComponentByClass(UTimerComponent::StaticClass()));
	return tuple;
}

void TimerSystem::TickTuple(SystemTuple* systemTuple, float deltaTime)
{
	TimerSystemTuple* tuple = static_cast<TimerSystemTuple*>(systemTuple);
	TArray<Timer>& timers = tuple->m_TimerComponent->GetTimers();
	for (Timer& timer : timers)
	{
		timer.m_Timer = timer.m_Timer - deltaTime;
	}
}