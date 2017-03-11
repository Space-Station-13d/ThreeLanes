// Fill out your copyright notice in the Description page of Project Settings.

#include "ThreeLanes.h"
#include "GridCell.h"
#include "Grid.h"

// Sets default values
AGridCell::AGridCell()
{
	X = Y = 0;

	SceneRoot = RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
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
}

