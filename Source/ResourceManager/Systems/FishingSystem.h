// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Components/InventoryComponent.h"
#include "Components/InteractionComponent.h"
#include "Components/TimerComponent.h"
#include "Components/InputsComponent.h"

class AActor;
class AInteraction;

struct FishingSystemTuple: public SystemTuple 
{
	UInventoryComponent* m_Inventory;
	UInteractionComponent* m_InteractionComponent;
	UTimerComponent* m_TimerComponent;
	UInputsComponent* m_Inputs;
};

class RESOURCEMANAGER_API FishingSystem : public System
{
public:
	FishingSystem();
	virtual ~FishingSystem();
protected:
	virtual bool CanRegister(AActor* actor) const override;
	virtual FString GetName() const override { return FString("Fishing"); }
	virtual SystemTuple* CreateTuple(AActor* actor) const override;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) override;
	void Fish(UInteractionComponent* interactionComponent, UTimerComponent* timerComponent);
	void FishingResult(AInteraction* interactionActor, UInventoryComponent* inventoryComponent);

};
