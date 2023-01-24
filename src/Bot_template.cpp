#include "Bot_template.h"

int Bot_Template::get_chosen_piece_type()
{
	return chosen_piece;
}

pair <int, int> Bot_Template::get_chosen_board_field()
{
	return chosen_board_field;
}

void Bot_Template::analyze_position(Quarto_game* game, int piece)
{
	board = game->get_board();

	GAME_DIFFICULTY = game->get_game_difficulty_level();

	for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
	{
		pieces[i] = !game->is_piece_used(i);
	}
}