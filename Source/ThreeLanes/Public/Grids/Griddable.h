// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Griddable.generated.h"

class AGridCell;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THREELANES_API UGriddable : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY()
	AGridCell* Cell;

public:
	// Sets default values for this component's properties
	UGriddable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// These get invoked by cells.
	void Attach(AGridCell* NewCell);
	void Detach();

	/**
	 * Gets the cell we are attached to.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	AGridCell* GetCell();
};
