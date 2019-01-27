// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "InputsComponent.generated.h"

class UInputComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESOURCEMANAGER_API UInputsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInputsComponent();
	TMap<FKey, bool>* GetInputs() { return &m_inputs; }
	APlayerController* GetPlayerController() { return GetWorld()->GetFirstPlayerController(); }
	void SetKeyDown(FKey key, bool pressed) 
	{ 
		if (m_inputs.Contains(key))
		{
			m_inputs.Emplace(key, pressed);
		}
		else
		{
			m_inputs.Add(key, pressed);
		}
	}
	bool GetCanMove() { return m_CanMove; }
	void SetCanMove(bool canMove) { m_CanMove = canMove; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FKey, bool> m_inputs;
	bool m_CanMove;
};
