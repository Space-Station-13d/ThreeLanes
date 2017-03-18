// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreeLanes.h"
#include "Grids/Griddable.h"
#include "Grids/GridCell.h"

// Sets default values for this component's properties
UGriddable::UGriddable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGriddable::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UGriddable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AGridCell* UGriddable::GetCell()
{
	return Cell;
}

void UGriddable::Attach(AGridCell* NewCell)
{
	Cell = NewCell;
}

void UGriddable::Detach()
{
	Cell = nullptr;
}
