//
//  TicTacToe.h
//  tic_tac_toe game
//
//  Created by Yufan Luo on 1/11/20.
//  Copyright © 2020 Yufan Luo. All rights reserved.
//

#ifndef TicTacToe_h
#define TicTacToe_h

using namespace std;


class TicTacToe
{
    
public:
    
    
    TicTacToe();
    ~TicTacToe();
    
    void TicTacToe_startGame();

    
private:
    
    void TicTacToe_init();
    void TicTacToe_printWelcome();
    void TicTacToe_printBoard();
    void TicTacToe_printUserTurnScreen();
    void TicTacToe_getWhoStartFirst();
    void TicTacToe_getUserPiece();
    void TicTacToe_getPcPiece();
    int  TicTacToe_dfsDecisionMaker(bool myTurn, int CurrDepth, \
                int maxDepth, int &xIndex, int &yIndex);
    inline void TicTacToe_set_position_user (int i, int j);
    inline void TicTacToe_set_position_computer (int i, int j);
    inline void TicTacToe_clear_position (int i, int j);
    void TicTacToe_set_position_indicator();
    void TicTacToe_clear_position_indicator();
    inline bool TicTacToe_is_position_indicator();
    void TicTacToe_set_user_first_player();
    void TicTacToe_clear_user_first_player();
    inline bool TicTacToe_is_user_first_player();
    void TicTacToe_set_player1_turn();
    void TicTacToe_reverse_player1_turn();
    inline bool TicTacToe_is_player1_turn();
    inline bool TicTacToe_isNum(string s);
    inline int TicTacToe_toInt(string s);
    inline bool TicTacToe_ifOccupied (int i, int j);
    inline string TicTacToe_remove_space(string s);
    inline bool TicTacToe_is_user_turn();
    int  TicTacToe_checkIfGameEnded();
    void TicTacToe_playEndMsg(int i);
    bool TicTacToe_getUserPlayAgain();
    

/* we do not support TICTACTOE_TABLE_SIZE > 9*/
#define TICTACTOE_TABLE_SIZE       3
#define TICTACTOE_TOTAL_SLOTS      TICTACTOE_TABLE_SIZE*TICTACTOE_TABLE_SIZE
/* by game rule, NUM_TO_WIN <= TABLE_SIZE */
#define TICTACTOE_NUM_TO_WIN       3
#define TICTACTOE_PLAYER1_MARK    "X"
#define TICTACTOE_PLAYER2_MARK    "O"
#define TICTACTOE_PLAYER1_PIECE   -1
#define TICTACTOE_PLAYER2_PIECE   -2
#define TICTACTOE_CELL_OCCUPIED    TICTACTOE_PLAYER1_PIECE
    
/*
 * we use 1 to TICTACTOE_TABLE_SIZE^2 to denote position
 * in chessboard - board[][]
 * > 0 values means the cell is empty and available
 * < 0 values means the cell is occupied
 * TODO: this could be further optimized or improved.
 */
    int board[TICTACTOE_TABLE_SIZE][TICTACTOE_TABLE_SIZE];

/* object flag used to indicate object status */
#define TICTACTOE_FLAG_SHOW_POSITION_INDICATOR  0x01
#define TICTACTOE_FLAG_IS_USER_PLAYER1          0x02
#define TICTACTOE_FLAG_IS_PLAYER1_TURN          0x04
    
    int TicTacToe_flag;

/* the messages we will use in the game */
    enum TicTacToe_msg_list {
        TicTacToe_msg_welcome = 0,
        TicTacToe_msg_boardsize,
        TicTacToe_msg_winCond,
        TicTacToe_msg_winCondEnd,
        TicTacToe_msg_boardIndicator,
        TicTacToe_msg_whoStartFirst,
        TicTacToe_msg_warningYorN,
        TicTacToe_msg_getUserPiece,
        TicTacToe_msg_getUserPieceEnd,
        TicTacToe_msg_currentChess,
        TicTacToe_msg_showAvailPos,
        TicTacToe_msg_hideAvailPos,
        TicTacToe_msg_userMark,
        TicTacToe_msg_pcMark,
        TicTacToe_msg_posOccupied,
        TicTacToe_msg_warningNum,
        TicTacToe_msg_warningNumEnd,
        TicTacToe_msg_userWin,
        TicTacToe_msg_pcWin,
        TicTacToe_msg_draw,
        TicTacToe_msg_playAgain,
        TicTacToe_msg_num
    };

    static const string TicTacToe_msg[TicTacToe_msg_num];
    
};

#endif /* TicTacToe_h */
