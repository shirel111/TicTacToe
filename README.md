# Tic Tac Toe Game

A customizable NxN game where players alternate placing their marks (X or O) on the board. The objective is to align M consecutive marks (horizontally, vertically, or diagonally) to win.

## How to Run
1. Clone the repository to your local machine.
2. Open the project in Visual Studio or any C++ IDE.
3. Build and run the solution.

## Game Rules
- The board is of size NxN, and players alternate placing X or O in empty cells.
- The first player to get M consecutive marks (horizontally, vertically, or diagonally) wins.
- Each cell on the board is uniquely numbered until it’s filled by a player.
- The game checks for valid input, ensuring players only choose available cells.

## Features
- Customizable board size (N x N).
- Customizable sequence length (M).
- Input validation at each turn.
- The board is printed after each move.
- A main method is included to test the game with a 4x4 board and a sequence length of 4.

## Instructions
1. Players take turns placing their marks (X or O) on the board.
2. After each turn, the board is updated and displayed.
3. The game checks if any player has achieved a winning sequence of M consecutive marks.
