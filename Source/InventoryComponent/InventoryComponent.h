// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInventory, Log, All);


USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName ItemId = NAME_None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 ObjectSize = 0;

};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DRAINRATS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	bool AddItem(FName ItemId, int32 ObjectSize);

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TArray<FInventorySlot> InventorySlots;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MaxSlots = 10;


public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
