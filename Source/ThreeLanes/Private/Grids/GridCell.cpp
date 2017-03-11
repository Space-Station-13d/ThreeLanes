// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreeLanes.h"
#include "GridCell.h"
#include "Grid.h"

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
	if (bNew)
	{
		UE_LOG(LogGrid, Log, TEXT("New: true"), bNew);
	}
	else
	{
		UE_LOG(LogGrid, Log, TEXT("New: false"), bNew);
	}

	SceneRoot->SetVisibility(bNew);
}