// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Structures/Item.h"
#include "ItemSlot.generated.h"

USTRUCT(BlueprintType)
struct FItemSlot
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UItem> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity;
};
