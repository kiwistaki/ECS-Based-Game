// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "System.h"
#include "Components/InventoryComponent.h"

struct InventorySystemTuple : public SystemTuple
{
	UInventoryComponent* m_Inventory;
};

class RESOURCEMANAGER_API InventorySystem : public System
{
public:
	InventorySystem();
	~InventorySystem();
protected:
	virtual bool CanRegister(AActor* actor) const override;
	virtual FString GetName() const override { return FString("Inventory"); }
	virtual SystemTuple* CreateTuple(AActor* actor) const override;
	virtual void TickTuple(SystemTuple* systemTuple, float deltaTime) override;

private:
	void GetSlotIndexWithItem(TArray<FItemSlot>& slots, const TSubclassOf<UItem>& itemClass, int& slotIndex, bool& success);
	void GetFreeSlotIndex(TArray<FItemSlot>& slots, int& slotIndex, bool& success);
};
