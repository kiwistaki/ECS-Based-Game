// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "InteractionType.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class FInteractionType : uint8
{
	None,
	FishingSpot,
	Shop
};
