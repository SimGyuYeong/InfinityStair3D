// Fill out your copyright notice in the Description page of Project Settings.


#include "Stair.h"

// Sets default values
AStair::AStair()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStair::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStair::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

