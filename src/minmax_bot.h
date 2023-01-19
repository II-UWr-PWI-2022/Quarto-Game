#ifndef EMPTY_BOT_H
#define EMPTY_BOT_H

#include <string>
#include "Quarto_game.h"

using namespace std;

class Bot
{
    char board[4][4];
    bool pieces[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    bool is_board_winning();
    int evaluate(int piece);
    int minmax(int depth,int piece,int max_depth);
    pair<int,int> ans_board_field;
    int ans_piece;
    const int EMPTY=16;
    const int MAX_BOARD_VALUE=100;
    const int MIN_BOARD_VALUE=0;
public:

    int get_piece_type();
    pair<int,int> get_board_field(Quarto_game *game,int piece);
};

#endif //EMPTY_BOT_H