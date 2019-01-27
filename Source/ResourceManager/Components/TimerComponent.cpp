// Fill out your copyright notice in the Description page of Project Settings.

#include "TimerComponent.h"


// Sets default values for this component's properties
UTimerComponent::UTimerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTimerComponent::GetTime(int id, bool& success, float& time)
{
	success = false;
	for (Timer timer : m_Timers)
	{
		if (timer.m_Id == id)
		{
			time = timer.m_Timer;
			success = true;
			return;
		}
	}
}
