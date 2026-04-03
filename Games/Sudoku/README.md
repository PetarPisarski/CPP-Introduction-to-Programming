# C++ Sudoku Generator & Player

A lightweight, terminal-based Sudoku game written in C++.  
This project was developed as a personal challenge during my first semester to practice **recursion**, **backtracking algorithms**, and **multidimensional arrays**.

---

## Features

### Procedural Generation
Uses a **recursive backtracking algorithm** to generate a valid, full Sudoku board every time.

### Custom Difficulty
Choose how many cells to clear (**1–64**), allowing for puzzles ranging from **"Beginner"** to **"Insane"**.

### Input Validation
- Checks for **row**, **column**, and **3 × 3 grid** conflicts
- Prevents users from overwriting the **initial puzzle numbers**

### Dynamic UI
A formatted **ASCII game board** that updates in real-time in the terminal.

---

## How to Play

### Set Difficulty
When prompted, enter the number of squares you want to be **empty** *(maximum 64)*.

### Make a Move
Enter your move in the format:

```
ROW COL NUM
```

**Example:**
```
1 5 7
```
Places a **7** at **Row 1, Column 5**.

### Win Condition
Fill the entire board correctly to see the **"GG WP"** message.

### Quit
Enter:
```
0 0 0
```
at any time to exit the game.

---

## Logic Breakdown

### Generation
The `fillBoard()` function uses **recursion** to attempt placing numbers **1–9**.  
If it reaches a dead end, it **backtracks** by resetting the cell to `0` and trying a different path.

### Validation
The `isValid()` function ensures Sudoku rules are satisfied:
- No duplicate in the same **row**
- No duplicate in the same **column**
- No duplicate in the same **3 × 3 sub-grid**

---

## Future Improvements

- Implement a **Solver** feature to show the solution if the player gives up
- Add a **timer** to track solve time (not sure if possible in a c++ terminal app)
- Improve randomization to ensure each puzzle has a **unique solution**

---

## About

Created as a **first-semester programming milestone**.