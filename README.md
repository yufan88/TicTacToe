# Tic Tac Toe

This is a simple c++ implementation of Tic-Tac-Toe game. The game is played by a single player v.s. computer.

## Gameplay:

The player is able to choose go first or computer go first at the welcome page.
The chess board size and victory condition is also displayed here.

========================================
===== Welcome to Tic Tac Toe Game! =====
========================================
========================================

Current chessboard size: 3
Current victory condition: 3 in a row
Current chessboard position: 
	*************************
	*       *       *       *
	*   1   *   2   *   3   *
	*       *       *       *
	*************************
	*       *       *       *
	*   4   *   5   *   6   *
	*       *       *       *
	*************************
	*       *       *       *
	*   7   *   8   *   9   *
	*       *       *       *
	*************************


Do you want to go first? (Y or N): 

Player needs to select a number to place his piece at the corresponding cell, for chess size 3, the cell number is 1 - 9.
For example, here player can choose 5 to place his piece at the center of the chessboard.


It is your turn, enter your position (1-9): 5

This is current chessboard :
Your mark: X,  Computer's mark: O

	*************************
	*       *       *       *
	*   O   *       *       *
	*       *       *       *
	*************************
	*       *       *       *
	*       *   X   *       *
	*       *       *       *
	*************************
	*       *       *       *
	*       *       *       *
	*       *       *       *
	*************************

(show available positions by entering "P")
It is your turn, enter your position (1-9): 

The system does not accept invalid inputs, but it is not case sensitive.

It is your turn, enter your position (1-9): t
Invalid input, please enter (1-9): 

The player is able to show/hide the position indicator during the game by pressing P/H.

Invalid input, please enter (1-9): P

This is current chessboard :
Your mark: X,  Computer's mark: O

	*************************
	*       *       *       *
	*   O   *   2   *   3   *
	*       *       *       *
	*************************
	*       *       *       *
	*   4   *   X   *   6   *
	*       *       *       *
	*************************
	*       *       *       *
	*   7   *   8   *   9   *
	*       *       *       *
	*************************

(hide available positions by entering "H")
It is your turn, enter your position (1-9): H

This is current chessboard :
Your mark: X,  Computer's mark: O

	*************************
	*       *       *       *
	*   O   *       *       *
	*       *       *       *
	*************************
	*       *       *       *
	*       *   X   *       *
	*       *       *       *
	*************************
	*       *       *       *
	*       *       *       *
	*       *       *       *
	*************************

(show available positions by entering "P")
It is your turn, enter your position (1-9):

After the game, user is able to choose play again or not.

(show available positions by entering "P")
It is your turn, enter your position (1-9): 9

	*************************
	*       *       *       *
	*   O   *   O   *   X   *
	*       *       *       *
	*************************
	*       *       *       *
	*   X   *   X   *   O   *
	*       *       *       *
	*************************
	*       *       *       *
	*   O   *   X   *   X   *
	*       *       *       *
	*************************


********* Draw! Let's play again! *********


Do you want to play again? (Y or N):

The computer is using DFS algorithm to find the optimal step, therefore, the player can never win the game. (The outcome of the game is a tie or lose for player.)

## Method:
