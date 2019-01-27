// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structures/ItemData.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class RESOURCEMANAGER_API UItem : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FItemData ItemData;
};
