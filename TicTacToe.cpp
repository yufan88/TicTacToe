//
//  TicTacToe.cpp
//  tic_tac_toe game
//
//  Created by Yufan Luo on 1/11/20.
//  Copyright © 2020 Yufan Luo. All rights reserved.
//

#include <iostream>
#include <string>

#include "TicTacToe.h"

using namespace std;

/* Public Functions for TicTacToe */

/* Constructor */
TicTacToe::TicTacToe()
{
    TicTacToe_init();
}

/*
 * Destructor
 * We don't do anything for destructor currently
 */
TicTacToe::~TicTacToe()
{
    return;
}

/*
 * Let's start the GAME!
 */
void TicTacToe::TicTacToe_startGame()
{
    
    TicTacToe_printWelcome();
    TicTacToe_getWhoStartFirst();
    
    while (1) {
    
        int GameEnded = 0;
    
        while (!GameEnded) {
        
            if (TicTacToe_is_user_turn()) {
                TicTacToe_printUserTurnScreen();
                TicTacToe_getUserPiece();
            } else {
                TicTacToe_getPcPiece();
            }
        
            GameEnded = TicTacToe_checkIfGameEnded();
            TicTacToe_reverse_player1_turn();
        }
    
        TicTacToe_playEndMsg(GameEnded);
        
        if (TicTacToe_getUserPlayAgain()) {
            TicTacToe_init();
            TicTacToe_getWhoStartFirst();
        }
        else break;
    }
}


/* Private Functions for TicTacToe */

/* init for static varibales */
const string TicTacToe::TicTacToe_msg[] = {
    "========================================\n"
    "========================================\n"
    "===== Welcome to Tic Tac Toe Game! =====\n"
    "========================================\n"
    "========================================\n\n",   // TicTacToe_msg_welcome
    "Current chessboard size: ",                      // TicTacToe_msg_boardsize
    "Current victory condition: ",                    // TicTacToe_msg_winCond
    " in a row",                                      // TicTacToe_msg_winCondEnd
    "Current chessboard position: ",                  // TicTacToe_msg_boardIndicator
    "Do you want to go first? (Y or N): ",            // TicTacToe_msg_whoStartFirst
    "Invalid input, please enter (Y or N): ",         // TicTacToe_msg_warningYorN
    "It is your turn, enter your position (1-",       // TicTacToe_msg_getUserPiece
    "): ",                                            // TicTacToe_msg_getUserPieceEnd
    "This is current chessboard :\n",                 // TicTacToe_msg_currentChess
    "(show available positions by entering \"P\")",   // TicTacToe_msg_showAvailPos
    "(hide available positions by entering \"H\")",   // TicTacToe_msg_hideAvailPos
    "Your mark: ",                                    // TicTacToe_msg_userMark
    ",  Computer's mark: ",                           // TicTacToe_msg_pcMark
    "This cell is occupied, try another one: ",       // TicTacToe_msg_posOccupied
    "Invalid input, please enter (1-",                // TicTacToe_msg_warningNum
    "): ",                                            // TicTacToe_msg_warningNumEnd
    "===========================================\n"
    "****** Congratulations!!! You Won!!! ******\n"
    "****** Winner Winner, Chicken Dinner ******\n"
    "===========================================\n",  // TicTacToe_msg_userWin
    "****** Computer Won. Let's try again! ******\n", // TicTacToe_msg_pcWin
    "********* Draw! Let's play again! *********\n",  // TicTacToe_msg_draw
    "Do you want to play again? (Y or N):",           // TicTacToe_msg_playAgain
};

/*
 * Init for TicTacToe checkerboard
 * We put position number to board[TICTACTOE_TABLE_SIZE].
 */
void TicTacToe::TicTacToe_init()
{
    for (int i = 1; i <= TICTACTOE_TOTAL_SLOTS; ++i)
        board[(i-1)/TICTACTOE_TABLE_SIZE][(i-1)%TICTACTOE_TABLE_SIZE] = i;
    
    /* init flag here */
    TicTacToe_flag = 0;
    TicTacToe_set_player1_turn();
}

/* set position_indicator true */
void TicTacToe::TicTacToe_set_position_indicator() {
    TicTacToe_flag |= TICTACTOE_FLAG_SHOW_POSITION_INDICATOR;
}

/* clear position_indicator bit */
void TicTacToe::TicTacToe_clear_position_indicator() {
    TicTacToe_flag &= ~TICTACTOE_FLAG_SHOW_POSITION_INDICATOR;
}

/* show position_indicator */
inline bool TicTacToe::TicTacToe_is_position_indicator() {
    return (TicTacToe_flag & TICTACTOE_FLAG_SHOW_POSITION_INDICATOR);
}

/* set user is first player true */
void TicTacToe::TicTacToe_set_user_first_player() {
    TicTacToe_flag |= TICTACTOE_FLAG_IS_USER_PLAYER1;
}

/* clear user is first player */
void TicTacToe::TicTacToe_clear_user_first_player() {
    TicTacToe_flag &= ~TICTACTOE_FLAG_IS_USER_PLAYER1;
}

/* show position_indicator */
inline bool TicTacToe::TicTacToe_is_user_first_player() {
    return (TicTacToe_flag & TICTACTOE_FLAG_IS_USER_PLAYER1);
}

/* set it is player1's turn true */
void TicTacToe::TicTacToe_set_player1_turn() {
    TicTacToe_flag |= TICTACTOE_FLAG_IS_PLAYER1_TURN;
}

/* reverse it is player1's turn bit */
void TicTacToe::TicTacToe_reverse_player1_turn() {
    TicTacToe_flag ^= TICTACTOE_FLAG_IS_PLAYER1_TURN;
}

/* show it is player1's turn bit */
inline bool TicTacToe::TicTacToe_is_player1_turn() {
    return (TicTacToe_flag & TICTACTOE_FLAG_IS_PLAYER1_TURN);
}

/* set board[i][j] to be user's piece */
inline void TicTacToe::TicTacToe_set_position_user (int i, int j) {
    if (TicTacToe_is_user_first_player()) board[i][j] = TICTACTOE_PLAYER1_PIECE;
    else board[i][j] = TICTACTOE_PLAYER2_PIECE;
}

/* set board[i][j] to be computer's piece */
inline void TicTacToe::TicTacToe_set_position_computer (int i, int j) {
    if (TicTacToe_is_user_first_player()) board[i][j] = TICTACTOE_PLAYER2_PIECE;
    else board[i][j] = TICTACTOE_PLAYER1_PIECE;
}

/* clear board[i][j] to be empty */
inline void TicTacToe::TicTacToe_clear_position (int i, int j) {
    board[i][j] = i * TICTACTOE_TABLE_SIZE + j + 1;
}

/*
 * Check if the game has ended
 * @return
 *      @ TICTACTOE_PLAYER1_WON      player 1 wins
 *      @ TICTACTOE_PLAYER2_WON      player 2 wins
 *      @ TICTACTOE_DRAW             game draw
 *      @ TICTACTOE_GAME_NOT_ENDED   game has not yet ended
 */

int TicTacToe::TicTacToe_checkIfGameEnded()
{
#define TICTACTOE_GAME_NOT_ENDED   0
#define TICTACTOE_PLAYER1_WON      TICTACTOE_PLAYER1_PIECE
#define TICTACTOE_PLAYER2_WON      TICTACTOE_PLAYER2_PIECE
#define TICTACTOE_DRAW             (TICTACTOE_PLAYER1_WON+TICTACTOE_PLAYER2_WON)
    
    int last_h, last_v, last_h2, last_v2;
    int check_h_num, check_v_num, check_h_num2, check_v_num2;
    bool chessboardfull = true;
    
    /* check -| */
    for (int i = 0; i < TICTACTOE_TABLE_SIZE; ++i) {
        
        last_h = 0;
        last_v = 0;
        check_h_num = 0;
        check_v_num = 0;
        
        for (int j = 0; j < TICTACTOE_TABLE_SIZE; ++j) {
            if (board[i][j] == last_h) ++check_h_num;
            else {
                last_h = board[i][j];
                check_h_num = 1;
            }
            if (board[j][i] == last_v) ++check_v_num;
            else {
                last_v = board[j][i];
                check_v_num = 1;
            }
            if (board[i][j] > 0) chessboardfull = false;
            if (check_h_num >= TICTACTOE_NUM_TO_WIN) return last_h;
            if (check_v_num >= TICTACTOE_NUM_TO_WIN) return last_v;
        }
    }
    
    /* check /\ */
    for (int i = 0; i <= TICTACTOE_TABLE_SIZE - TICTACTOE_NUM_TO_WIN; ++i) {
        
        last_h = 0;
        last_v = 0;
        check_h_num = 0;
        check_v_num = 0;
        last_h2 = 0;
        last_v2 = 0;
        check_h_num2 = 0;
        check_v_num2 = 0;
        
        for (int j = 0; j < TICTACTOE_TABLE_SIZE - i; ++j) {
            if (board[j][i + j] == last_h) ++check_h_num;
            else {
                last_h = board[j][i + j];
                check_h_num = 1;
            }
            if (board[i + j][j] == last_h2) ++check_h_num2;
            else {
                last_h2 = board[i + j][j];
                check_h_num2 = 1;
            }
            
            if (board[j][TICTACTOE_TABLE_SIZE - 1 - i - j] == last_v) ++check_v_num;
            else {
                last_v = board[j][TICTACTOE_TABLE_SIZE - 1 - i - j];
                check_v_num = 1;
            }
            if (board[i + j][TICTACTOE_TABLE_SIZE - 1 - j] == last_v2) ++check_v_num2;
            else {
                last_v2 = board[i + j][TICTACTOE_TABLE_SIZE - 1 - j];
                check_v_num2 = 1;
            }
            
            if (check_h_num >= TICTACTOE_NUM_TO_WIN) return last_h;
            if (check_h_num2 >= TICTACTOE_NUM_TO_WIN) return last_h2;
            if (check_v_num >= TICTACTOE_NUM_TO_WIN) return last_v;
            if (check_v_num2 >= TICTACTOE_NUM_TO_WIN) return last_v2;
        }
    }
    
    if (chessboardfull) return TICTACTOE_DRAW;
    
    return TICTACTOE_GAME_NOT_ENDED;
}

/*
 * This function is used to print user's turn msg
 */
void TicTacToe::TicTacToe_printUserTurnScreen() {
    
    cout << endl << endl << TicTacToe_msg[TicTacToe_msg_currentChess];
    cout << TicTacToe_msg[TicTacToe_msg_userMark] << \
    (TicTacToe_is_user_first_player() ? TICTACTOE_PLAYER1_MARK : TICTACTOE_PLAYER2_MARK) << \
    TicTacToe_msg[TicTacToe_msg_pcMark] << \
    (TicTacToe_is_user_first_player() ? TICTACTOE_PLAYER2_MARK : TICTACTOE_PLAYER1_MARK) << endl;
    cout << endl;
    
    TicTacToe_printBoard();
    
    if (!TicTacToe_is_position_indicator()) {
        cout << TicTacToe_msg[TicTacToe_msg_showAvailPos] << endl;
    } else {
        cout << TicTacToe_msg[TicTacToe_msg_hideAvailPos] << endl;
    }
    
    cout << TicTacToe_msg[TicTacToe_msg_getUserPiece] << \
    TICTACTOE_TOTAL_SLOTS << \
    TicTacToe_msg[TicTacToe_msg_getUserPieceEnd];
    
}

/*
 * This function is used to print welcome msg
 */
void TicTacToe::TicTacToe_printWelcome() {
    cout << TicTacToe_msg[TicTacToe_msg_welcome];
    cout << TicTacToe_msg[TicTacToe_msg_boardsize] << TICTACTOE_TABLE_SIZE << endl;
    cout << TicTacToe_msg[TicTacToe_msg_winCond] << TICTACTOE_NUM_TO_WIN << \
        TicTacToe_msg[TicTacToe_msg_winCondEnd] << endl;
    cout << TicTacToe_msg[TicTacToe_msg_boardIndicator] << endl;
    TicTacToe_set_position_indicator();
    TicTacToe_printBoard();
    TicTacToe_clear_position_indicator();
    cout << endl;
}

/*
 * This function is used to print end msg
 */
void TicTacToe::TicTacToe_playEndMsg(int i) {
    cout << endl;
    TicTacToe_printBoard();
    cout << endl;
    if (i == TICTACTOE_DRAW) {
        cout << TicTacToe_msg[TicTacToe_msg_draw] << endl;
        return;
    }
    if ((i == TICTACTOE_PLAYER1_WON && TicTacToe_is_user_first_player())|| \
         (i == TICTACTOE_PLAYER2_WON && !TicTacToe_is_user_first_player())) {
        cout << TicTacToe_msg[TicTacToe_msg_userWin] << endl;
    } else {
        cout << TicTacToe_msg[TicTacToe_msg_pcWin] << endl;
    }
}

/*
 * This function gets user play again
 */
bool TicTacToe::TicTacToe_getUserPlayAgain() {
    string userInput;
    cout << endl << TicTacToe_msg[TicTacToe_msg_playAgain];
    getline(cin, userInput);
    userInput = TicTacToe_remove_space(userInput);
    /* need to do sanity check */
    while (userInput != "Y" && userInput != "N") {
        cout << TicTacToe_msg[TicTacToe_msg_warningYorN];
        getline(cin, userInput);
        userInput = TicTacToe_remove_space(userInput);
    }
    if (userInput == "Y") return true;
    return false;
}

/*
 * This function returns if this is user's turn
 */
inline bool TicTacToe::TicTacToe_is_user_turn() {
    return ((TicTacToe_is_user_first_player() && TicTacToe_is_player1_turn()) || \
             (!TicTacToe_is_user_first_player() && !TicTacToe_is_player1_turn()));
}

/*
 * This function gets who start first from user
 */
void TicTacToe::TicTacToe_getWhoStartFirst() {
    string userInput;
    cout << TicTacToe_msg[TicTacToe_msg_whoStartFirst];
    getline(cin, userInput);
    userInput = TicTacToe_remove_space(userInput);
    /* need to do sanity check */
    while (userInput != "Y" && userInput != "N") {
        cout << TicTacToe_msg[TicTacToe_msg_warningYorN];
        getline(cin, userInput);
        userInput = TicTacToe_remove_space(userInput);
    }
    if (userInput == "Y") TicTacToe_set_user_first_player();
    else TicTacToe_clear_user_first_player();
    return;
}

/* refine a input string by removing spaces and uppercasing */
inline string TicTacToe::TicTacToe_remove_space(string s) {
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

/*
 * This function detects if the input is a number
 */
inline bool TicTacToe::TicTacToe_isNum(string s) {
    if (s.length() == 0) return false;
    for (char c : s){
        if (!isdigit(c)) return false;
    }
    return true;
}

/*
 * This function converts string to int
 */
inline int TicTacToe::TicTacToe_toInt(string s) {
    size_t len = s.length();
    if (len == 0) return INT_MAX;
    size_t found = s.find_first_not_of("0");
    s = s.substr(found, len);
    if (s.length() > 2) return INT_MAX;
    return stoi(s);
}

/*
 * This function detects if a cell is occupied
 */
inline bool TicTacToe::TicTacToe_ifOccupied (int i, int j) {
    return (board[i][j] <= TICTACTOE_CELL_OCCUPIED);
}

/*
 * This function gets user's pieces
 */
void TicTacToe::TicTacToe_getUserPiece() {
    string userInput;
    int val, xIndex, yIndex;
    getline(cin, userInput);
    userInput = TicTacToe_remove_space(userInput);
    /* need to do sanity check */
    while (1) {
        if (userInput == "P") {
            TicTacToe_set_position_indicator();
            TicTacToe_printUserTurnScreen();
        } else if (userInput == "H") {
            TicTacToe_clear_position_indicator();
            TicTacToe_printUserTurnScreen();
        } else if (TicTacToe_isNum(userInput) && \
                   ((val = TicTacToe_toInt(userInput)) >= 1) && \
                   val <= TICTACTOE_TOTAL_SLOTS) {
            xIndex = (val - 1)/TICTACTOE_TABLE_SIZE;
            yIndex = (val - 1)%TICTACTOE_TABLE_SIZE;
            if (TicTacToe_ifOccupied(xIndex, yIndex)) {
                cout << TicTacToe_msg[TicTacToe_msg_posOccupied];
            } else {
                TicTacToe_set_position_user(xIndex, yIndex);
                break;
            }
        } else {
            cout << TicTacToe_msg[TicTacToe_msg_warningNum] << \
            TICTACTOE_TOTAL_SLOTS << TicTacToe_msg[TicTacToe_msg_warningNumEnd];
        }
        
        getline(cin, userInput);
        userInput = TicTacToe_remove_space(userInput);
    }
    return;
}

/*
 * DFS algorithm for next step
 * due to DFS limitation, for TICTACTOE_TABLE_SIZE > 4
 * The calculation will be forever
 *
 * @ param
 *      @ myTurn - The current turn is computer's
 *      @ CurrDepth - The current search depth, starting from 0
 *      @ maxDepth - The maximal depth for dfs, we don't want to stay
 *                   in this function forever
 *      @ xIndex, yIndex - optimal x, y index for the next step
 * @ return
 *      @ Points - the points we gonna get for the optimal strategy
 *
 * @TODU: better evaluation algorithm should be developped. Current DFS
 *        is only ok for table size <= 3
 */

int TicTacToe::TicTacToe_dfsDecisionMaker(bool myTurn, int CurrDepth, int maxDepth, \
                                               int &xIndex, int &yIndex)
{
#define PC_WIN_POINTS     1
#define USER_WIN_POINTS  -1
#define DRAW_POINTS       0
#define NO_INFO           0
    
    int Points;
    int GameResult, nextPoints;
    if (myTurn) Points = INT_MIN;
    else Points = INT_MAX;
    
    for (int i = 0; i < TICTACTOE_TABLE_SIZE; ++i) {
        for (int j = 0; j < TICTACTOE_TABLE_SIZE; ++j) {
            if (!TicTacToe_ifOccupied(i, j)) {
                
                /* find best result if it is computer's turn */
                if (myTurn) {
                    TicTacToe_set_position_computer(i, j);
                    GameResult = TicTacToe_checkIfGameEnded();
                    if (GameResult) {
                        TicTacToe_clear_position (i, j);
                        if (CurrDepth == 0) {
                            xIndex = i;
                            yIndex = j;
                        }
                        if (GameResult == TICTACTOE_DRAW) return DRAW_POINTS;
                        return PC_WIN_POINTS;
                    }
                    
                    /* we have tried our best, just return here */
                    if (CurrDepth == maxDepth) {
                        TicTacToe_clear_position (i, j);
                        return NO_INFO;
                    }
                    
                    /* dfs recursion */
                    nextPoints = TicTacToe_dfsDecisionMaker(!myTurn, CurrDepth + 1, maxDepth, \
                                                            xIndex, yIndex);
                    if (nextPoints > Points) {
                        Points = nextPoints;
                        if (CurrDepth == 0) {
                            xIndex = i;
                            yIndex = j;
                        }
                        /* at this point, we know we are gonna win */
                        if (Points >= PC_WIN_POINTS) {
                            TicTacToe_clear_position (i, j);
                            return PC_WIN_POINTS;
                        }
                    }
                
                /* find the worst solution under user's turn */
                } else {
                    
                    TicTacToe_set_position_user(i, j);
                    GameResult = TicTacToe_checkIfGameEnded();
                    if (GameResult) {
                        TicTacToe_clear_position (i, j);
                        if (GameResult == TICTACTOE_DRAW) return DRAW_POINTS;
                        return USER_WIN_POINTS;
                    }
                    
                    /* we have tried our best, just return here */
                    if (CurrDepth == maxDepth) {
                        TicTacToe_clear_position (i, j);
                        return NO_INFO;
                    }
                    
                    /* dfs recursion */
                    nextPoints = TicTacToe_dfsDecisionMaker(!myTurn, CurrDepth + 1, maxDepth, \
                                                            xIndex, yIndex);
                    
                    if (nextPoints < Points) {
                        Points = nextPoints;
                        /* at this point, we know we are gonna lose */
                        if (Points <= USER_WIN_POINTS) {
                            TicTacToe_clear_position (i, j);
                            return USER_WIN_POINTS;
                        }
                    }
                    
                }
                
                TicTacToe_clear_position (i, j);
                
            }
        }
    }
    return Points;
}


/*
 * This function gets computer's pieces
 * currently we are using dfs algorithm
 */
void TicTacToe::TicTacToe_getPcPiece()
{
#define DFS_MAX_DEPTH    TICTACTOE_TOTAL_SLOTS
    
    int xIndex, yIndex;
    
    TicTacToe_dfsDecisionMaker(true, 0, DFS_MAX_DEPTH, xIndex, yIndex);
    
    TicTacToe_set_position_computer (xIndex, yIndex);
}

/*
 * This function is used to print chessboard
 * for > 0 numbers, we print their values
 * for TICTACTOE_PLAYER1_PIECE, we print 'X'
 * for TICTACTOE_PLAYER2_PIECE, we print 'O'
 */
void TicTacToe::TicTacToe_printBoard()
{
    
/* TICTACTOE_CELL_WIDTH has to be >= 4 in order to have space to print */
#define TICTACTOE_CELL_WIDTH  9
    
/* TICTACTOE_CELL_LEN has to be >= 3 int order to have space to print */
#define TICTACTOE_CELL_LEN    5
    
/* (TICTACTOE_CELL_LEN - 1) * TICTACTOE_TABLE_SIZE + 1 rows in total */
#define TICTACTOE_BOARD_ROW_NUM ((TICTACTOE_CELL_LEN - 1) * TICTACTOE_TABLE_SIZE + 1)
    
/* (TICTACTOE_CELL_WIDTH - 1) * TICTACTOE_TABLE_SIZE + 1 column in total */
#define TICTACTOE_BOARD_COL_NUM ((TICTACTOE_CELL_WIDTH - 1) * TICTACTOE_TABLE_SIZE + 1)
    
    int index = 0, val;
    
    for (int i = 0; i < TICTACTOE_BOARD_ROW_NUM; ++i) {
        cout << "\t";
        for (int j = 0; j < TICTACTOE_BOARD_COL_NUM; ++j) {
            
            /* print walls */
            if (!(i % (TICTACTOE_CELL_LEN - 1)) || !(j % (TICTACTOE_CELL_WIDTH - 1))) cout << "*";
            
            /* print position indicators and players' pieces */
            else if (((i - TICTACTOE_CELL_LEN/2) % (TICTACTOE_CELL_LEN - 1)) == 0 &&
                     ((j - TICTACTOE_CELL_WIDTH/2) % (TICTACTOE_CELL_WIDTH - 1)) == 0) {
                
                val = board[index / TICTACTOE_TABLE_SIZE][index % TICTACTOE_TABLE_SIZE];
                
                /* print val in corresponding format */
                if (val == TICTACTOE_PLAYER1_PIECE) cout << TICTACTOE_PLAYER1_MARK;
                else if (val == TICTACTOE_PLAYER2_PIECE) cout << TICTACTOE_PLAYER2_MARK;
                else if (TicTacToe_is_position_indicator()) {
                    cout << val;
                    /* for two digit-number, we need one more extra space */
                    if (val >= 10) ++j;
                }
                else cout << " ";
                ++index;
            }
            else cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


int main(int argc, const char * argv[]) {
    
    TicTacToe t;
    t.TicTacToe_startGame();
    return 0;
}
