#ifndef EMPTY_BOT_H
#define EMPTY_BOT_H

#include <string>
#include "Quarto_game.h"

using namespace std;

class Bot
{
    char board[4][4];
    bool pieces[16] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    pair<int,int> ans_board_field;
    int ans_piece;
    const int EMPTY=16;
public:

    int get_piece_type();
    pair<int,int> get_board_field(Quarto_game *game,int piece);
    //char get_row();
    //char get_column();
};

#endif //EMPTY_BOT_H