#ifndef BOT_RANDOM_H
#define BOT_RANDOM_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"

class Bot_Random
{
    pair <int, int> chosen_board_field = {0, 0};
    int chosen_piece = 0;

public:
    int get_chosen_piece_type();
    pair <int, int> get_chosen_board_field();
    void analyze_position(Quarto_game* game, int piece);
};

#endif