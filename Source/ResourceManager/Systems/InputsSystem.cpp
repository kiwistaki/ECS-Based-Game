// Fill out your copyright notice in the Description page of Project Settings.

#include "InputsSystem.h"

InputsSystem::InputsSystem()
{
}

InputsSystem::~InputsSystem()
{
}

bool InputsSystem::CanRegister(AActor* actor) const
{
	return actor->GetComponentByClass(UInputsComponent::StaticClass()) != nullptr;
}

SystemTuple* InputsSystem::CreateTuple(AActor* actor) const
{
	InputsSystemTuple* tuple = new InputsSystemTuple;
	tuple->m_inputs = Cast<UInputsComponent>(actor->GetComponentByClass(UInputsComponent::StaticClass()));
	return tuple;
}

void InputsSystem::TickTuple(SystemTuple* systemTuple, float deltaTime)
{
	InputsSystemTuple* tuple = static_cast<InputsSystemTuple*>(systemTuple);
	UInputsComponent* input = tuple->m_inputs;
	APlayerController* controller = input->GetPlayerController();
	if (controller->IsInputKeyDown(EKeys::F))
	{
		input->SetKeyDown(EKeys::F, true);
	}
	else
	{
		input->SetKeyDown(EKeys::F, false);
	}
}