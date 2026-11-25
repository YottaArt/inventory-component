// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

DEFINE_LOG_CATEGORY(LogInventory);

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogInventory, Warning, TEXT("Begin Play has been started"));
	UE_LOG(LogInventory, Error, TEXT("Inventory has been build wrong"));
	UE_LOG(LogInventory, Display, TEXT("This is dislay message"));

	// ...
	
}


bool UInventoryComponent::AddItem(FName ItemId, int32 ObjectSize) 
{
	if (ItemId.IsNone() || ObjectSize <= 0 || ObjectSize > MaxSlots) {
		return false;
	}

	int32 UsedSlots = 0;
	
	for (int i = 0; i < InventorySlots.Num(); i++) {
		UsedSlots += InventorySlots[i].ObjectSize;
	}

	UsedSlots += ObjectSize;
	if (UsedSlots > MaxSlots) {
		return false;
	}
	
	FInventorySlot NewSlot;
	NewSlot.ItemId = ItemId;
	NewSlot.ObjectSize = ObjectSize;

	InventorySlots.Add(NewSlot);
	return true;
}