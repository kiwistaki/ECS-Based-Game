// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySystem.h"

InventorySystem::InventorySystem()
{
}

InventorySystem::~InventorySystem()
{
}

bool InventorySystem::CanRegister(AActor* actor) const
{
	return actor->GetComponentByClass(UInventoryComponent::StaticClass()) != nullptr;
}

SystemTuple* InventorySystem::CreateTuple(AActor* actor) const
{
	InventorySystemTuple* tuple = new InventorySystemTuple;
	tuple->m_Inventory = Cast<UInventoryComponent>(actor->GetComponentByClass(UInventoryComponent::StaticClass()));
	return tuple;
}

void InventorySystem::TickTuple(SystemTuple* systemTuple, float deltaTime)
{
	InventorySystemTuple* tuple = static_cast<InventorySystemTuple*>(systemTuple);

	TArray<TSubclassOf<UItem>>& pendingAddItems = tuple->m_Inventory->GetPendingAddItems();
	TArray<FItemSlot>& slots = tuple->m_Inventory->GetSlots();
	for (TSubclassOf<UItem>& pendingAddItem : pendingAddItems)
	{
		int slotWithItem;
		bool success;
		GetSlotIndexWithItem(slots, pendingAddItem, slotWithItem, success);
		if (success)
		{
			slots[slotWithItem].Quantity++;
			tuple->m_Inventory->SetUpdateUIRequested(true);
			UE_LOG(LogTemp, Warning, TEXT("Added item in slot"));
		}
		else
		{
			int freeSlotIndex;
			GetFreeSlotIndex(slots, freeSlotIndex, success);
			if (success)
			{
				slots[freeSlotIndex].ItemClass = pendingAddItem;
				slots[freeSlotIndex].Quantity = 1;
				tuple->m_Inventory->SetUpdateUIRequested(true);

				UE_LOG(LogTemp, Warning, TEXT("Added item in free slot"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("No more free space in inventory"));
			}
		}
	}
	pendingAddItems.Empty();

	TArray<int32>& pendingRemoveItemIndices = tuple->m_Inventory->GetPendingRemoveItemIndices();
	for (int32 index : pendingRemoveItemIndices)
	{
		if (index >= 0 && index <= slots.Num() && slots[index].Quantity > 0)
		{
			slots[index].Quantity--;
			tuple->m_Inventory->SetUpdateUIRequested(true);
		}
	}
	pendingRemoveItemIndices.Empty();
}

void InventorySystem::GetSlotIndexWithItem(TArray<FItemSlot>& slots, const TSubclassOf<UItem>& itemClass, int& slotIndex, bool& success)
{
	for (int i = 0; i < slots.Num(); ++i)
	{
		if (slots[i].ItemClass == itemClass)
		{
			slotIndex = i;
			success = true;
			return;
		}
	}
	success = false;
}

void InventorySystem::GetFreeSlotIndex(TArray<FItemSlot>& slots, int& slotIndex, bool& success)
{
	UE_LOG(LogTemp, Warning, TEXT("TEST"));
	for (int i = 0; i < slots.Num(); ++i)
	{
		if (slots[i].Quantity == 0)
		{
			slotIndex = i;
			success = true;
			return;
		}
	}
	success = false;
}
