# Unreal Engine 5.6 – Inventory Component

## Overview

A C++ inventory component developed in Unreal Engine 5.6 as part of the game project.

The component is designed to manage inventory slots, track item sizes and enforce inventory capacity limits.

**Development status:** Work in progress.

## Current Features

- **Inventory slots:** Stores item information using a custom `FInventorySlot` structure.
- **Item identification:** Uses `FName` to identify individual items.
- **Item size:** Each inventory slot stores the size occupied by its item.
- **Capacity limit:** Supports a configurable maximum inventory capacity, set to 10 by default.
- **AddItem function:** Allows items to be added while checking inventory capacity.

### AddItem – Current Implementation

The `AddItem` function currently:

1. Checks that the item ID is valid.
2. Checks that the item size is positive.
3. Rejects items larger than the total inventory capacity.
4. Calculates the space currently occupied by existing items.
5. Rejects an item if adding it would exceed the capacity.
6. Adds the item to the inventory if all checks pass.

Items are currently stored as separate entries. Item stacking has not been implemented.

## Technical Details

| Component | Implementation |
|---|---|
| Engine | Unreal Engine 5.6 |
| Language | C++ |
| Inventory storage | `TArray<FInventorySlot>` |
| Item identifier | `FName` |
| Item size | `int32` |
| Default capacity | 10 |

## Project Structure

- `InventoryComponent.h` – Inventory component declaration and `FInventorySlot` structure.
- `InventoryComponent.cpp` – Inventory component implementation and item management logic.

## Planned Features

- Remove items from inventory.
- Improve item management and validation.
- Introduce item definitions and data assets.
- Implement item pickups.
- Add inventory UI.
- Explore crafting and multiplayer functionality.

## Development Notes

This repository documents the development progress of the inventory component. Features listed under Planned Features are not yet implemented.
