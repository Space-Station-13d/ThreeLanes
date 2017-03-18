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

	/**
	 * The thing that's currently attached to us.
	 */
	UPROPERTY()
	UGriddable* Current;

public:
	// Sets default values for this actor's properties
	AGridCell();

	void Initialize(AGrid* NewMaster, int32 X, int32 Y);

	void SetDebugDraw(bool bNew);

	UPROPERTY(BlueprintReadOnly, Category="Grid")
	int32 X;

	UPROPERTY(BlueprintReadOnly, Category="Grid")
	int32 Y;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	ATerrainFeature* GetTerrainFeature();

	UFUNCTION(BlueprintCallable, Category="Grid")
	void SetTerrainFeature(ATerrainFeature* New);

	UFUNCTION(BlueprintCallable, Category="Grid")
	void ClearTerrainFeature();

	/**
	 * Get the currently attached object.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid", meta=(DisplayName="Get Contents"))
	UGriddable* GetCurrent();

	/**
	 * Sets the currently attached object.
	 */
	UFUNCTION(BlueprintCallable, Category="Grid", meta=(DisplayName="Set Contents"))
	void SetCurrent(UGriddable* New);

	/**
	 * Clears the currently attached object.
	 */
	UFUNCTION(BlueprintCallable, Category="Grid", meta=(DisplayName="Clear Contents"))
	void ClearCurrent();

	/**
	 * Returns a cell with coordinates relative to us.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	AGridCell* GetRelative(int32 RelX=0, int32 RelY=0);

	/**
	 * Gets a cell neighboring us.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	AGridCell* GetNeighbor(EGridNeighbor Neighbor);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	AGrid* GetMaster();
};
