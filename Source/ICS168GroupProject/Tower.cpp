// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Tower.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;

	sizeRadius = 30.0f;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	SphereComponent->InitSphereRadius(sizeRadius);
	SphereComponent->SetCollisionProfileName(TEXT("Towers"));
	RootComponent = SphereComponent;

}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//My Functions :)

float ATower::getSellPrice()
{
	return sellPrice;
}

float ATower::getSize()
{
	return sizeRadius;
}

/*
FString ATower::getName()
{
	return towerName;
}
*/
void ATower::sell()
{
	Destroy();
}

void ATower::updateFootprint()
{
	SphereComponent->SetSphereRadius(sizeRadius);
}