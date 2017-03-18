// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreeLanes.h"
#include "Grids/GridCell.h"
#include "Grids/Grid.h"
#include "Grids/TerrainFeature.h"

// Sets default values
AGridCell::AGridCell()
{
	X = Y = 0;

	RootComponent = SceneRoot = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	const ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	const ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/Materials/Debug/GridDebugCubeMaterial'"));
	if (Mesh.Object != nullptr)
	{
		SceneRoot->SetStaticMesh(Mesh.Object);
	}
	if (Material.Object != nullptr)
	{
		SceneRoot->SetMaterial(0, Material.Object);
	}
	SceneRoot->bVisible = false;
}

void AGridCell::Initialize(AGrid* NewMaster, int32 NewX, int32 NewY)
{
	if (Master != nullptr)
	{
		// Already got a master apparently...
		UE_LOG(LogGrid, Fatal, TEXT("AGridCell::Initialize called, but this cell already has a master!"));
	}
	Master = NewMaster;
	X = NewX;
	Y = NewY;

	// Align ourselves.
	AttachToActor(Master, FAttachmentTransformRules::KeepWorldTransform);
	SetActorRelativeLocation(FVector(Master->CellSize.X * X, Master->CellSize.Y * Y, 0));
	if (Master->bDrawDebug)
	{
		SetDebugDraw(true);
	}
}

void AGridCell::SetDebugDraw(bool bNew)
{
	SceneRoot->SetVisibility(bNew);
}

ATerrainFeature* AGridCell::GetTerrainFeature()
{
	return TerrainFeature;
}

void AGridCell::SetTerrainFeature(ATerrainFeature* New)
{
	TerrainFeature = New;
}

void AGridCell::ClearTerrainFeature()
{
	TerrainFeature = nullptr;
}

UGriddable* AGridCell::GetCurrent()
{
	return nullptr;
}

void AGridCell::SetCurrent(UGriddable* New)
{
	Current = New;
}

void AGridCell::ClearCurrent()
{
	Current = nullptr;
}

AGridCell* AGridCell::GetRelative(int32 RelX, int32 RelY)
{
	return Master->GetCell(X + RelX, Y + RelY);
}

AGridCell* AGridCell::GetNeighbor(EGridNeighbor Neighbor)
{
	int32 RelX = 0;
	int32 RelY = 0;

	switch (Neighbor)
	{
		case EGridNeighbor::North:
			RelY = 1;
			break;
		case EGridNeighbor::South:
			RelY = -1;
			break;
		case EGridNeighbor::East:
			RelX = 1;
			break;
		case EGridNeighbor::West:
			RelX = -1;
			break;
	}

	return GetRelative(RelX, RelY);
}

AGrid* AGridCell::GetMaster()
{
	return Master;
}
