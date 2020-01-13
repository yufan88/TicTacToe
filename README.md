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
#define TICTACTOE_PLAYER1_MARK    "X"
#define TICTACTOE_PLAYER2_MARK    "O"
```
Player's mark

```
#define TICTACTOE_CELL_WIDTH  9
#define TICTACTOE_CELL_LEN    5
```
Chessboard size for display

```
int board[TICTACTOE_TABLE_SIZE][TICTACTOE_TABLE_SIZE];
```
Chessboard, >1 values indicates the cell is empty, <0 values indicates the cell is occupied

```
int TicTacToe_flag;
```
Current class status:<br/>
0x01  if user has turned on position indicator<br/>
0x02  if user has chosen to go first<br/>
0x04  if it is user's turn to go

```
static const string TicTacToe_msg[TicTacToe_msg_num];
```
All the messages we will use in the game

```
void TicTacToe_startGame();
```
Start the main loop of the game

```
TicTacToe_getWhoStartFirst();
```
Prompt user for who should go first

```
TicTacToe_getUserPiece();
```
Prompt user to place a piece on the chessboard

```
TicTacToe_getPcPiece();
```
Get the next step for computer

```
TicTacToe_checkIfGameEnded();
```
Check if the game is ended

```
TicTacToe_getUserPlayAgain();
```
Prompt user for play again


## Limitations:

Current DecisionMaker is using DFS algorithm, and it is guaranteed that the computer will use the optimal strategy. Therefore, the player can never win the game.<br/>
However, the DFS algorithm is computational intense. For n size table game, the computational complexity will be O(n!). If we want to extend this game to > 4\*4 table size, better evaluation algorithm is badly needed.
