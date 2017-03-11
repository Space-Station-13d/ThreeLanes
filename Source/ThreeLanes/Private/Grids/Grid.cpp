// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreeLanes.h"
#include "Grid.h"
#include "GridCell.h"


// Sets default values
AGrid::AGrid()
{
	DimensionX = DimensionY = 0;
	CellSize = FVector2D(1, 1);

	RootComponent = SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
}

void AGrid::InitializeGrid(int32 X, int32 Y)
{
	DimensionX = X;
	DimensionY = Y;

	// We know exactly how much cells we need.
	Cells.Reserve(X * Y);

	for (int32 y = 0; y < Y; y++)
	{
		for (int32 x = 0; x < X; x++)
		{
			AGridCell* NewCell = (AGridCell*)GetWorld()->SpawnActor(AGridCell::StaticClass());
			NewCell->Initialize(this, x, y);
			Cells.Push(NewCell);
			UE_LOG(LogGrid, Log, TEXT("Initialized cell at (%d, %d)"), x, y);
		}
	}
}

void AGridTest::BeginPlay()
{
	Super::BeginPlay();

	InitializeGrid(X, Y);
}