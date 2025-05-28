# Tic Tac Toe Game (C++ Console Version)

This is a simple console-based *Tic Tac Toe* game written in C++. It allows two players to take turns, select their marks (X or O), and play against each other on a 3x3 board.

## Features

- Two-player gameplay
- Interactive name and mark selection
- Board displayed after every move
- Win detection (rows, columns, diagonals)
- Draw detection
- Option to replay
bash
Task 2/
└── Tic_Tac_Toe.cpp       # Source code of the Tic Tac Toe game
└── README.md


## How to Compile

Use any C++ compiler (like g++, clang++, etc.):

bash
g++ -o tic_tac_toe Tic_Tac_Toe.cpp

## How to Run
bash
./tic_tac_toe

## Game Instructions
- On running the game, both players will be asked to enter their names.

- One player selects their mark (X or O), and the other gets the remaining one.

- Players take turns entering positions (1-9) to mark their spot.

- The game checks for a winner or a draw after every move.

- At the end of a match, players are asked if they want to play again.
