#ifndef BOT_TEMPLATE_H
#define BOT_TEMPLATE_H

#include "Libraries_and_macros.hpp"
#include "Quarto_game.hpp"

class Bot_Template
{
private:
	vector <vector <int>> board = vector <vector <int>> (MAX_N, vector <int> (MAX_N));
	vector <bool> pieces = vector <bool> (MAX_NUMBER_OF_PIECES, true);

	pair <int, int> chosen_board_field = {0, 0};
	int chosen_piece = 0;

	bool GAME_DIFFICULTY;

public:
	int get_chosen_piece_type();
	pair <int, int> get_chosen_board_field();
	void analyze_position(Quarto_game* game, int piece);
};

#endif