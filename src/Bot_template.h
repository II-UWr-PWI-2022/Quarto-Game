#ifndef EMPTY_BOT_H
#define EMPTY_BOT_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"

class Bot
{
	vector <vector <int>> board = vector <vector <int>> (MAX_N, vector <int> (MAX_N));
    vector <bool> pieces = vector <bool>  (MAX_NUMBER_OF_PIECES, true);

    pair<int,int> ans_board_field;
    int ans_piece;
public:

    int get_chosen_piece_type();
    pair <int, int> get_chosen_board_field(Quarto_game* game, int piece);

    int get_piece_type();
    pair<int,int> get_board_field(Quarto_game *game,int piece);
    //char get_row();
    //char get_column();
};

#endif //EMPTY_BOT_H