#ifndef BOT_RANDOM_H
#define BOT_RANDOM_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"
#include "Piece.h"

class Bot
{
    char board[MAX_N][MAX_N];
    vector <bool> pieces = vector <bool>  (MAX_NUMBER_OF_PIECES, true);

    // bool is_line_winning(char p1, char p2, char p3, char p4);
    // bool is_board_winning();
    // int evaluate(int piece);
    // int minmax(int depth,int piece,int max_depth);
    pair <int, int> ans_board_field;
    int ans_piece;
    const int EMPTY = 16;
    // const int MAX_BOARD_VALUE = 650;
    // const int MIN_BOARD_VALUE = 0;
public:
    int get_piece_type();
    pair <int, int> get_board_field(Quarto_game *game, int piece);
};

#endif