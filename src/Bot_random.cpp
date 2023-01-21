#include "Bot_random.h"

int rand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

int Bot_Random::get_chosen_piece_type()
{
    return chosen_piece;
}

pair <int, int> Bot_Random::get_chosen_board_field()
{
	return chosen_board_field;
}

void Bot_Random::analyze_position(Quarto_game* game, int piece)
{
    vector <vector <int>> board = game->get_board();

	vector <pair <int, int>> fields;

    for(int row = 0; row < MAX_N; row++)
    {
        for(int column = 0; column < MAX_N; column++)
        {
			if(board[row][column] == EMPTY_FIELD)
			{
				fields.push_back({row, column});
			}
		}
	}

	int field_index = rand(0, (int) fields.size() - 1);

	vector <int> available_pieces;

	for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
	{
		if(game->is_piece_used(i))
		{
			available_pieces.push_back(i);
		}
	}

	int chosen_piece_for_oponent = rand(0, (int) available_pieces.size() - 1);

	chosen_piece = chosen_piece_for_oponent;
	chosen_board_field = fields[field_index];
}