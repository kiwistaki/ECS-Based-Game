// Fill out your copyright notice in the Description page of Project Settings.

#include "FishingSystem.h"
#include "Actors/Interaction.h"

FishingSystem::FishingSystem()
{
}

FishingSystem::~FishingSystem()
{
}

bool FishingSystem::CanRegister(AActor* actor) const
{
	return actor->GetComponentByClass(UInventoryComponent::StaticClass()) != nullptr &&
		   actor->GetComponentByClass(UInteractionComponent::StaticClass()) != nullptr &&
		   actor->GetComponentByClass(UTimerComponent::StaticClass()) != nullptr &&
		   actor->GetComponentByClass(UInputsComponent::StaticClass()) != nullptr;
}

SystemTuple* FishingSystem::CreateTuple(AActor* actor) const
{
	FishingSystemTuple* tuple = new FishingSystemTuple;
	tuple->m_Inventory = Cast<UInventoryComponent>(actor->GetComponentByClass(UInventoryComponent::StaticClass()));
	tuple->m_InteractionComponent = Cast<UInteractionComponent>(actor->GetComponentByClass(UInteractionComponent::StaticClass()));
	tuple->m_TimerComponent = Cast<UTimerComponent>(actor->GetComponentByClass(UTimerComponent::StaticClass()));
	tuple->m_Inputs = Cast<UInputsComponent>(actor->GetComponentByClass(UInputsComponent::StaticClass()));
	return tuple;
}

void FishingSystem::TickTuple(SystemTuple* systemTuple, float deltaTime)
{
	FishingSystemTuple* tuple = static_cast<FishingSystemTuple*>(systemTuple);
	TArray<AActor*> interactionActors = tuple->m_InteractionComponent->GetInteractionActors();
	bool* pressed = tuple->m_Inputs->GetInputs()->Find(EKeys::F);
	if (pressed != nullptr)
	{
		if (!*pressed && tuple->m_Inputs->GetCanMove())
		{
			return;
		}
	}
	else 
	{
		return;
	}
	if (tuple->m_InteractionComponent->IsInteracting())
	{
		for (int i = 0; i < interactionActors.Num(); i++)
		{
			AActor* actor = interactionActors[i];
			if (actor->IsA<AInteraction>())
			{
				AInteraction* interactionActor = Cast<AInteraction>(actor);
				if (interactionActor->GetInteractionType() == FInteractionType::FishingSpot)
				{
					bool success = false;
					float time = 0.0f;
					tuple->m_TimerComponent->GetTime(tuple->m_InteractionComponent->GetTimerId(), success, time);
					if (success)
					{
						if (time < 0.0f)
						{
							FishingResult(interactionActor, tuple->m_Inventory);
							tuple->m_InteractionComponent->SetIsInteracting(false);
							tuple->m_Inputs->SetCanMove(true);
							// Remove timer
						}
					}

				}
			}
		}
		return;
	}
	for (int i = 0; i < interactionActors.Num(); i++)
	{
		AActor* actor = interactionActors[i];
		if (actor->IsA<AInteraction>())
		{
			AInteraction* interactionActor = Cast<AInteraction>(actor);
			if (interactionActor->GetInteractionType() == FInteractionType::FishingSpot)
			{
					tuple->m_InteractionComponent->SetIsInteracting(true);
					tuple->m_Inputs->SetCanMove(false);

					int timerId = tuple->m_TimerComponent->GetNextId();
					tuple->m_TimerComponent->SetNextId(++timerId);
					tuple->m_InteractionComponent->SetTimerId(timerId);

					Timer timer = { timerId, 5.0f };
					tuple->m_TimerComponent->GetTimers().Add(timer);

					Fish(tuple->m_InteractionComponent, tuple->m_TimerComponent);
			}
		}
	}
}

void FishingSystem::Fish(UInteractionComponent* interactionComponent, UTimerComponent* timerComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("You're fishing... somehow..."));
	// Call AnimationComponent to start animation of fishing
}

void FishingSystem::FishingResult(AInteraction* interactionActor, UInventoryComponent* inventoryComponent)
{
	// Do some loot operations
	UE_LOG(LogTemp, Warning, TEXT("You got a fish... somehow..."));
	//inventoryComponent->GetPendingAddItems().Add(interactionActor);
}