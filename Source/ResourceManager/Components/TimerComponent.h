// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimerComponent.generated.h"

struct Timer
{
	int m_Id;
	float m_Timer;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESOURCEMANAGER_API UTimerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimerComponent();
	TArray<Timer>& GetTimers() { return m_Timers; }
	void GetTime(int id, bool& success, float& time);
	int GetNextId() { return m_NextId; }
	void SetNextId(int id) { m_NextId = id; }

protected:
	TArray<Timer> m_Timers;
	int m_NextId = 0;
};
