// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ECSWorld.generated.h"

class System;

UCLASS()
class RESOURCEMANAGER_API AECSWorld : public AActor
{
	GENERATED_BODY()
	
public:	
	AECSWorld();
	~AECSWorld();
	virtual void Tick(float DeltaTime) override;
	void RegisterActor(AActor* actor);
	void UnregisterActor(AActor* actor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	TArray<System*> m_Systems;
};
