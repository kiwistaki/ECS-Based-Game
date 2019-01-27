// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Components/InputsComponent.h"

struct InputsSystemTuple : public SystemTuple
{
	UInputsComponent* m_inputs;
};

class RESOURCEMANAGER_API InputsSystem : public System
{
public:
	InputsSystem();
	virtual ~InputsSystem();
protected:
	virtual bool CanRegister(AActor* actor) const override;
	virtual FString GetName() const override { return FString("Inputs"); }
	virtual SystemTuple* CreateTuple(AActor* actor) const override;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) override;
};
