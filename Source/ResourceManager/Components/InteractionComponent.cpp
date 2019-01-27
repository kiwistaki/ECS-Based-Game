// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractionComponent.h"


// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent() :
	m_IsInteracting(false)
,	m_InteractingActor(nullptr)
,	m_TimerID(0)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

