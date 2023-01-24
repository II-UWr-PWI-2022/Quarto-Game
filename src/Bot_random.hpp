#ifndef BOT_RANDOM_H
#define BOT_RANDOM_H

#include "Libraries_and_macros.hpp"
#include "Quarto_game.hpp"

class Bot_Random
{
private:
	pair <int, int> chosen_board_field = {0, 0};
	int chosen_piece = 0;

	int random_int(int L, int R);

public:
	int get_chosen_piece_type();
	pair <int, int> get_chosen_board_field();
	void analyze_position(Quarto_game* game, int piece);
};

#endif