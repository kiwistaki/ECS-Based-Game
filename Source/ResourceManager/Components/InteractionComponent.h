// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

class AActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESOURCEMANAGER_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();
	TArray<AActor*>& GetInteractionActors() { return m_InteractionActors; }

	bool IsInteracting() const { return m_IsInteracting; }
	void SetIsInteracting(bool IsInteracting) { m_IsInteracting = IsInteracting; }

	int GetTimerId() const { return m_TimerID; }
	void SetTimerId(int id) { m_TimerID = id; }

	void SetInteractingActor(AActor* actor) { m_InteractingActor = actor; }
	AActor* GetInteractingActor() const { return m_InteractingActor; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> m_InteractionActors;
	bool m_IsInteracting;
	AActor* m_InteractingActor;
	int m_TimerID;
	
};
