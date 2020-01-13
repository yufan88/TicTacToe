# Tic Tac Toe

This is a simple c++ implementation of Tic-Tac-Toe game. The game is played by a single player v.s. computer.

## Gameplay:

The player is able to choose to go first or let computer go first at the welcome page.
The chessboard size and victory condition is also displayed here.

>===== Welcome to Tic Tac Toe Game! =====

>Current chessboard size: 3<br/>
>Current victory condition: 3 in a row<br/>
>Current chessboard position:<br/>

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

>Do you want to go first? (Y or N):<br/>

Player needs to select a number to place his piece at the corresponding cell, for chess size 3, the cell number is 1 - 9.
For example, here player can choose 5 to place his piece at the center of the chessboard.


>It is your turn, enter your position (1-9): 5

>This is current chessboard :<br/>
>Your mark: X,  Computer's mark: O

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

>(show available positions by entering "P")<br/>
>It is your turn, enter your position (1-9):

The system does not accept invalid inputs, but it is not case sensitive.

>It is your turn, enter your position (1-9): t<br/>
>Invalid input, please enter (1-9): 

The player is able to show/hide the position indicator during the game by pressing P/H.

>Invalid input, please enter (1-9): P

>This is current chessboard :<br/>
>Your mark: X,  Computer's mark: O

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

>(hide available positions by entering "H")<br/>
>It is your turn, enter your position (1-9): H

>This is current chessboard :<br/>
>Your mark: X,  Computer's mark: O

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

>(show available positions by entering "P")<br/>
>It is your turn, enter your position (1-9):

After the game, user is able to choose play again or not.

>(show available positions by entering "P")<br/>
>It is your turn, enter your position (1-9): 9

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

>\*\*\*\*\*\*\*\*\* Draw! Let's play again! \*\*\*\*\*\*\*\*\*


>Do you want to play again? (Y or N):

The computer is using DFS algorithm to find the optimal step, therefore, the player can never win the game. (The outcome of the game is a tie or lose for player.)

## Key Functions/Variables:

```
class TicTacToe {}
```
TicTacToe class

```
#define TICTACTOE_TABLE_SIZE       3
```
Game chessboard size

```
#define TICTACTOE_NUM_TO_WIN       3
```
Game victory condition (3 pieces in a row)

```
#define TICTACTOE_PLAYER1_MARK    "X"<br/>
#define TICTACTOE_PLAYER2_MARK    "O"
```
Player's mark

## Limitations:

Current DecisionMaker is using DFS algorithm, and it is guaranteed that the computer will use the optimal strategy. Therefore, the player can never win the game.<br/>
However, the DFS algorithm is computational intense. For n size table game, the computational complexity will be O(n!). If we want to extend this game to > 4\*4 table size, better evaluation algorithm is badly needed.
