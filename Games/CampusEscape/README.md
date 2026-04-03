# Campus Escape

Campus Escape is a terminal-based rogue-like game developed as a final project for the first semester. The player must navigate a randomly generated campus map, collect items, defeat enemies, and find the key to reach the exit.

---

## Game Rules

### Objectives
- The primary goal is to find the Key (K) and reach the Exit (X).
- The game ends in a win if the player steps on the Exit while the Key is in their inventory.
- The game ends in a loss if the player's health (HP) reaches zero.

---

## Map Symbols

| Symbol | Description |
|--------|------------|
| P | Player |
| # | Wall (Impassable) |
| . | Walkable floor |
| D | Deadline (Enemy type 1: 7 HP, 2 ATK) |
| E | Exam (Enemy type 2: 10 HP, 3 ATK) |
| C | Coffee (Item: Restores 5 HP) |
| S | Cheat Sheet (Item: Buffs ATK for next 3 hits) |
| K | Key (Required to win) |
| X | Exit |

---

## Combat Logic

- Combat is triggered when:
    - The player attempts to move into a space occupied by an enemy, or
    - An enemy moves into the player.
- The player always strikes first.
- If a player has "Buff Hits" from a Cheat Sheet, they deal 2 extra damage per hit.
- Combat continues until either the player or the enemy reaches 0 HP.
- If the enemy is defeated, it is removed from the map.

---

## Enemy Behavior

Enemies have two movement states:

### Hunting
- If the player is within 5 tiles (Manhattan distance), the enemy moves toward the player on the dominant axis.

### Wandering
- If the player is far away, the enemy moves in a random valid direction.

Enemies cannot move through walls or other enemies.

---

## How to Play

### Movement

Use the following keys followed by Enter to move the player:

| Key | Action |
|-----|--------|
| w | Move Up |
| s | Move Down |
| a | Move Left |
| d | Move Right |

---

### Inventory and Items

- Items are picked up automatically by walking over them.
- The inventory has a maximum capacity of 6 slots.

#### Using Items
1. Press 'u' followed by Enter.
2. Type the slot number (1-6) of the item you wish to use.

- Coffee (C) restores 5 HP, up to a maximum cap of 20.
- Cheat Sheets (S) provide a temporary attack boost for the next 3 combat strikes.
- The Key (K) is not consumed upon use; it must simply be present to use the Exit.

---

### Quit

Press 'q' followed by Enter to exit the game at any time.

---

## Future Updates

### Object Oriented Programming

The next iteration of this project will involve refactoring the entity management system. Currently, player and enemy data (HP, ATK, coordinates) are handled via primitive arrays and pointers. The update will implement Classes to encapsulate these properties and behaviors.

- Entity Base Class: To handle shared attributes like coordinates and health.
- Player Class: Derived class to handle inventory logic and specific player stats.
- Enemy Class: Derived class to handle AI movement logic and specific enemy types (Deadline and Exam).