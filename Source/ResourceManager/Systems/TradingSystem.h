// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Components/InventoryComponent.h"
#include "Components/InteractionComponent.h"

class AActor;

/**
 * 
 */

struct TradingSystemTuple : public SystemTuple
{
	UInventoryComponent* m_Inventory;
	UInteractionComponent* m_Interaction;
};

class RESOURCEMANAGER_API TradingSystem : public System
{
public:
	TradingSystem();
	virtual ~TradingSystem();
protected:
	virtual bool CanRegister(AActor* actor) const override;
	virtual FString GetName() const override { return FString("Trading"); }
	virtual SystemTuple* CreateTuple(AActor* actor) const override;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) override;
};
