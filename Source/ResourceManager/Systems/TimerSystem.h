// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Components/TimerComponent.h"


struct TimerSystemTuple : public SystemTuple
{
	UTimerComponent* m_TimerComponent;
};

class RESOURCEMANAGER_API TimerSystem : public System
{
public:
	TimerSystem();
	virtual ~TimerSystem();

protected:
	virtual bool CanRegister(AActor* actor) const override;
	virtual FString GetName() const override { return FString("Timer"); }
	virtual SystemTuple* CreateTuple(AActor* actor) const override;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) override;
};
