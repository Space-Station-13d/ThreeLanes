// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GridCell.generated.h"

// Forward declarations.
class ATerrainFeature;
class UGriddable;
class AGrid;

UENUM(BlueprintType)
enum class EGridNeighbor : uint8
{
	// Positive Y.
	North,
	// Negative Y.
	South,
	// Positive X.
	East,
	// Negative X.
	West
};

UCLASS(BlueprintType)
class THREELANES_API AGridCell : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SceneRoot;

	UPROPERTY()
	AGrid* Master;

	// The terrain feature.
	UPROPERTY()
	ATerrainFeature* TerrainFeature;

	// The current thing on this tile.
	UPROPERTY()
	UGriddable* Current;

public:
	// Sets default values for this actor's properties
	AGridCell();

	void Initialize(AGrid* NewMaster, int32 X, int32 Y);

	void SetDebugDraw(bool bNew);

	UPROPERTY(BlueprintReadOnly)
	int32 X;

	UPROPERTY(BlueprintReadOnly)
	int32 Y;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ATerrainFeature* GetTerrainFeature();

	UFUNCTION(BlueprintCallable)
	void SetTerrainFeature(ATerrainFeature* New);

	UFUNCTION(BlueprintCallable)
	void ClearTerrainFeature();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UGriddable* GetCurrent();

	UFUNCTION(BlueprintCallable)
	void SetCurrent(UGriddable* New);

	UFUNCTION(BlueprintCallable)
	void ClearCurrent();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AGridCell* GetRelative(int32 RelX=0, int32 RelY=0);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AGridCell* GetNeighbor(EGridNeighbor Neighbor);
};
