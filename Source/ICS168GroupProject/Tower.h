// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tower.generated.h"

UCLASS(Abstract, Blueprintable) //Blueprintable redunant, but just for posterity
class ICS168GROUPPROJECT_API ATower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Money")
	float sellPrice;
	
	UPROPERTY(EditDefaultsOnly, Category = "Money")
	float sizeRadius; //Footprint of the tower (area you cant place other towers in)

	UFUNCTION(BlueprintCallable)
	void updateFootprint();

	//UProperty(BlueprintReadWrite)
	//FString towerName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	float getSellPrice();
	UFUNCTION(BlueprintCallable)
	float getSize();
	//UFUNCTION(BlueprintCallable)
	//FString getName();


	UFUNCTION(BlueprintCallable)
	void sell(); //Does not handle money, is pretty much just a destroy method

	UFUNCTION(BlueprintImplementableEvent, CallInEditor)
	void Select();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor)
	void Unselect();

	// Sphere component used to test collision. (Footprint)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class USphereComponent* SphereComponent;

private:

};
