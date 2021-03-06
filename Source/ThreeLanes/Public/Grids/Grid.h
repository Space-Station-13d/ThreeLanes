// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Grid.generated.h"

class AGridCell;

UCLASS(BlueprintType)
class THREELANES_API AGrid : public AActor
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<AGridCell*> Cells;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY()
	int32 DimensionX;

	UPROPERTY()
	int32 DimensionY;

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	// Sets default values for this actor's properties
	AGrid();

	/**
	 * Initialize a grid with a specific size. It is an error to call this more than once.
	 */
	UFUNCTION(BlueprintCallable, Category="Grid")
	void InitializeGrid(int32 X, int32 Y);

	/**
	 * The size each cell is assumed to be. This determines how far the cells are placed from each other.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Grid")
	FVector2D CellSize;

	/**
	 * Enables debug drawing, which makes the cells be visible.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Grid")
	bool bDrawDebug;

	/**
	 * Get a cell at specific coordinates.
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Grid")
	AGridCell* GetCell(int32 X, int32 Y);
};

UCLASS(BlueprintType)
class THREELANES_API AGridTest : public AGrid
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Grid")
	int32 X;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Grid")
	int32 Y;
};
