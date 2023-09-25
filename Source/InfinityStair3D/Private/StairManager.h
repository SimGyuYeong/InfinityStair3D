// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StairManager.generated.h"

UCLASS()
class AStairManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStairManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnStair(int count);

private:
	FVector GetStairPosition();

	UPROPERTY(EditDefaultsOnly, Category = Stair)
		TSubclassOf<class AStair> StairClass;

public:
	UPROPERTY(EditAnywhere, Category = Stair)
		int InitSpawnStairCount = 10;

	UPROPERTY(EditAnywhere, Category = Stair)
		float AddPosZ = 200;

	UPROPERTY(EditAnywhere, Category = Stair)
		float AddPosXY = 170;

private:
	FVector stairPos = FVector(0, 0, 0);
};
