// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() :
	m_UpdateUIRequested(false)
,   m_Money(1000)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	SetUpdateUIRequested(true);
}

void UInventoryComponent::GetSlot(int slotIndex, TSubclassOf<UItem>& itemClass, int& quantity, bool& success) const
{
	if (slotIndex < 0 || slotIndex >= m_Slots.Num())
	{
		success = false;
		return;
	}

	const FItemSlot& slot = m_Slots[slotIndex];
	if (slot.Quantity == 0)
	{
		success = false;
		return;
	}

	itemClass = slot.ItemClass;
	quantity = slot.Quantity;
	success = true;
}