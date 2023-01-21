#include "Bot_random.h"

int rand(int a, int b)
{
	return a + rand() % (b - a + 1);
}

int Bot::get_piece_type()
{
    return ans_piece;
}

pair <int, int> Bot::get_board_field(Quarto_game *game, int piece)
{
	for(int row = 0; row < MAX_N; row++)
    {
        for(int column = 0; column < MAX_N; column++)
		{
            board[row][column] = game->get_piece_type_from_board_field(row,column);
        }
    }

	vector <pair <int, int>> fields;

    for(int row = 0; row < MAX_N; row++)
    {
        for(int column = 0; column < MAX_N; column++)
        {
			if(board[row][column] == EMPTY)
			{
				fields.push_back({row, column});
			}
		}
	}

	int field_index = rand(0, (int) fields.size() - 1);

	vector <int> available_pieces;

	for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
	{
		if(pieces[i])
		{
			available_pieces.push_back(i);
		}
	}

	int chosen_piece_for_oponent = rand(0, (int) available_pieces.size() - 1);

	ans_piece = chosen_piece_for_oponent;
	ans_board_field = fields[field_index];

    pieces[piece]=false;
    pieces[ans_piece]=false;

    return ans_board_field;
}