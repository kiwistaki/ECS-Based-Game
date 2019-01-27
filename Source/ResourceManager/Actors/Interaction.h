// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums/InteractionType.h"
#include "Interaction.generated.h"

UCLASS()
class RESOURCEMANAGER_API AInteraction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteraction();
	FInteractionType GetInteractionType() const { return m_InteractionType; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInteractionType m_InteractionType;
		
};
