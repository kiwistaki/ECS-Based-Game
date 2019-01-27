// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structures/ItemSlot.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESOURCEMANAGER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	virtual void BeginPlay() override;

	TArray<TSubclassOf<UItem>>& GetPendingAddItems() { return m_PendingAddItems; }
	TArray<int32>& GetPendingRemoveItemIndices() { return m_PendingRemoveItemIndices; }
	TArray<FItemSlot>& GetSlots() { return m_Slots; }

	UFUNCTION(BlueprintCallable)
	void GetSlot(int slotIndex, TSubclassOf<UItem>& itemClass, int& quantity, bool& success) const;
	void SetUpdateUIRequested(bool updateUIRequested) { m_UpdateUIRequested = updateUIRequested; }
	void SetMoney(int32 money) { m_Money = money; }
	int32 GetMoney() const { return m_Money; }
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FItemSlot> m_Slots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TSubclassOf<UItem>> m_PendingAddItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> m_PendingRemoveItemIndices;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool m_UpdateUIRequested;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 m_Money;
};
