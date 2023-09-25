// Fill out your copyright notice in the Description page of Project Settings.


#include "StairManager.h"
#include "Stair.h"

// Sets default values
AStairManager::AStairManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStairManager::BeginPlay()
{
	Super::BeginPlay();
	SpawnStair(InitSpawnStairCount);
}

// Called every frame
void AStairManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStairManager::SpawnStair(int count)
{
	if (StairClass)
	{
		for (int i = 0; i < count; ++i)
		{
			// Sphere 생성 위치를 지정합니다. 원하는 위치로 수정하세요.
			FVector direction = GetStairPosition() * FVector(AddPosXY, AddPosXY, 0);

			// 스폰위치 설정
			FVector spawnLocation = GetActorLocation() + stairPos + direction;
			spawnLocation.Z += AddPosZ;
			stairPos = spawnLocation;

			// Sphere 생성
			FActorSpawnParameters SpawnParams;
			GetWorld()->SpawnActor<AStair>(StairClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
		}
	}
}

FVector AStairManager::GetStairPosition()
{
	std::mt19937 randomEngine(std::random_device{}());
	std::uniform_real_distribution<float> distribution(0, 100);
	float randomValue = distribution(randomEngine);

	if (randomValue <= 25)
	{
		return FVector(1, 0, 0);
	}
	else if (randomValue <= 50)
	{
		return FVector(-1, 0, 0);
	}
	else if (randomValue <= 75)
	{
		return FVector(0, 1, 0);
	}
	else
	{
		return FVector(0, -1, 0);
	}
}