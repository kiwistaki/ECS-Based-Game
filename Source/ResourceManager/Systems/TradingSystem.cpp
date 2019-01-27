// Fill out your copyright notice in the Description page of Project Settings.

#include "TradingSystem.h"
#include "Components/InventoryComponent.h"
#include "Actors/ShopInteraction.h"

TradingSystem::TradingSystem()
{
}

TradingSystem::~TradingSystem()
{
}

bool TradingSystem::CanRegister(AActor* actor) const
{
	return actor->GetComponentByClass(UInventoryComponent::StaticClass()) != nullptr &&
		actor->GetComponentByClass(UInteractionComponent::StaticClass()) != nullptr;
}

SystemTuple* TradingSystem::CreateTuple(AActor* actor) const 
{
	TradingSystemTuple* tuple = new TradingSystemTuple;
	tuple->m_Inventory = Cast<UInventoryComponent>(actor->GetComponentByClass(UInventoryComponent::StaticClass()));
	tuple->m_Interaction = Cast<UInteractionComponent>(actor->GetComponentByClass(UInteractionComponent::StaticClass()));
	return tuple;
}

void TradingSystem::TickTuple(SystemTuple* systemTuple, float deltaTime)
{
	TradingSystemTuple* tuple = static_cast<TradingSystemTuple*>(systemTuple);

	if (tuple->m_Interaction->IsInteracting())
	{
		if (AActor* interactingActor = tuple->m_Interaction->GetInteractingActor())
		{
			if (interactingActor->IsA<AShopInteraction>())
			{
				AShopInteraction* shop = Cast<AShopInteraction>(interactingActor);
				const int32 numItemsInShop = shop->GetItems().Num();
				if (shop->GetRequestedBuyIndex() >= 0 && shop->GetRequestedBuyIndex() < numItemsInShop)
				{
					const TSubclassOf<UItem>& item = shop->GetItems()[shop->GetRequestedBuyIndex()];
					if (UItem* defaultItem = item->GetDefaultObject<UItem>())
					{
						const int32 money = tuple->m_Inventory->GetMoney();
						const int32 price = defaultItem->ItemData.BuyPrice;
						if (money >= price)
						{
							tuple->m_Inventory->SetMoney(money - price);
							tuple->m_Inventory->GetPendingAddItems().Add(item);
						}
					}
					shop->SetRequestedBuyIndex(-1);
				}

				if (shop->GetRequestedSellIndex() >= 0)
				{
					TSubclassOf<UItem> item;
					int32 quantity;
					bool success;
					tuple->m_Inventory->GetSlot(shop->GetRequestedSellIndex(), item, quantity, success);
					if (success && quantity > 0)
					{
						if (UItem* defaultItem = item->GetDefaultObject<UItem>())
						{
							const int32 money = tuple->m_Inventory->GetMoney();
							tuple->m_Inventory->SetMoney(money + defaultItem->ItemData.SellPrice);
							tuple->m_Inventory->GetPendingRemoveItemIndices().Add(shop->GetRequestedSellIndex());
						}
					}
					shop->SetRequestedSellIndex(-1);
				}

				if (shop->GetRequestedEndInteraction())
				{
					shop->CloseShopUI();
					shop->SetRequestedEndInteraction(false);
					tuple->m_Interaction->SetIsInteracting(false);
					tuple->m_Interaction->SetInteractingActor(nullptr);
				}
			}
		}
	}
	else
	{
		TArray<AActor*>& interactionActors = tuple->m_Interaction->GetInteractionActors();
		for (AActor* actor : interactionActors)
		{
			if (actor->IsA<AShopInteraction>())
			{
				AShopInteraction* shop = Cast<AShopInteraction>(actor);
				shop->SetRequestedBuyIndex(-1);
				shop->OpenShopUI();
				tuple->m_Interaction->SetIsInteracting(true);
				tuple->m_Interaction->SetInteractingActor(actor);
				break;
			}
		}
	}
}
