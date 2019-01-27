// Fill out your copyright notice in the Description page of Project Settings.

#include "InputsComponent.h"


// Sets default values for this component's properties
UInputsComponent::UInputsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	
	m_CanMove = true;
}
