// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/Interaction.h"
#include "Structures/Item.h"
#include "ShopInteraction.generated.h"

/**
 * 
 */
UCLASS()
class RESOURCEMANAGER_API AShopInteraction : public AInteraction
{
	GENERATED_BODY()
	
public:
	AShopInteraction();

	UFUNCTION(BlueprintImplementableEvent)
	void OpenShopUI();

	UFUNCTION(BlueprintImplementableEvent)
	void CloseShopUI();

	const TArray<TSubclassOf<UItem>>& GetItems() const { return m_Items; }
	void SetRequestedBuyIndex(int32 requestedBuyIndex) { m_RequestedBuyIndex = requestedBuyIndex; }
	int32 GetRequestedBuyIndex() const { return m_RequestedBuyIndex; }
	void SetRequestedSellIndex(int32 requestedSellIndex) { m_RequestedSellIndex = requestedSellIndex; }
	int32 GetRequestedSellIndex() const { return m_RequestedSellIndex; }
	void SetRequestedEndInteraction(bool requestedEndInteraction) { m_RequestedEndInteraction = requestedEndInteraction; }
	bool GetRequestedEndInteraction() const { return m_RequestedEndInteraction; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UItem>> m_Items;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 m_RequestedBuyIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 m_RequestedSellIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool m_RequestedEndInteraction;
};
