#include "Bot_minmax.hpp"

/*
	Returns random value from the range of numbers [L, R]
*/
int Bot_Minmax::random_int(int L, int R)
{
	return L + rand() % (R - L + 1);
}

/*
	Checks whether the given four fields share at least one common characteristics
*/
bool Bot_Minmax::is_pattern_winning(int p1, int p2, int p3, int p4)
{
	return ((((p1 | p2 | p3 | p4) & EMPTY_FIELD) == 0) && ((p1 & p2 & p3 & p4) || (~(p1 | p2 | p3 | p4) & MASK)));
}

/*
	Depending on game difficulty checks if there is a line or square
	of fields that share at least one common characteristics
*/
bool Bot_Minmax::is_board_winning()
{
	if(!GAME_DIFFICULTY)
	{
		// easy version of game, checks all the lines

		for(int row = 0; row < MAX_N; row++)
		{
			if(is_pattern_winning(board[row][0], board[row][1], board[row][2], board[row][3])) return true;
		}

		for(int column = 0; column < MAX_N; column++)
		{
			if(is_pattern_winning(board[0][column], board[1][column], board[2][column], board[3][column])) return true;
		}

		return (is_pattern_winning(board[0][0], board[1][1], board[2][2], board[3][3])
			|| is_pattern_winning(board[0][3], board[1][2], board[2][1], board[3][0]));
	}

	else
	{
		// hard version of game, checks all the squares

		for(int row = 0; row < MAX_N - 1; row++)
		{
			for(int column = 0; column < MAX_N - 1; column++)
			{
				if(is_pattern_winning(board[row][column], board[row + 1][column], board[row][column + 1], board[row + 1][column + 1])) return true;
			}
		}

		return false;
	}
}

int Bot_Minmax::evaluate(int given_piece)
{
	int value = 0;

	for(int i = 0; i < MAX_N; i++)
	{
		for(int j = 0; j < MAX_N; j++)
		{
			if(board[i][j] == EMPTY_FIELD)
			{
				board[i][j] = given_piece;

				if(is_board_winning()) value = MAX_BOARD_VALUE;

				board[i][j] = EMPTY_FIELD;
			}
		}
	}

	if(value == MAX_BOARD_VALUE) return value;

	int count[MAX_N][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};

	for(int piece = 0; piece < MAX_NUMBER_OF_PIECES; piece++)
	{
		if(pieces[piece] == false) continue;

		for(int i = 0; i < MAX_N; i++)
		{
			count[i][((piece & (1 << i)) > 0)]++;
		}
	}

	for(int i = 0; i < MAX_N; i++)
	{
		int andv = MASK, and_neg = MASK;

		for(int j = 0; j < MAX_N; j++)
		{
			if(board[i][j] == EMPTY_FIELD) continue;

			andv &= board[i][j];
			and_neg &= (board[i][j] ^ MASK);
		}

		for(int j = 0; j < MAX_N; j++)
		{
			if(andv & (1 << j)) value += count[j][1];
			if(and_neg & (1 << j)) value += count[j][0];
		}
	}

	for(int i = 0; i < MAX_N; i++)
	{
		int andv = MASK, and_neg = MASK;

		for(int j = 0; j < MAX_N; j++)
		{
			if(board[j][i] == EMPTY_FIELD) continue;

			andv &= board[j][i];
			and_neg &= (board[j][i] ^ MASK);
		}

		for(int j = 0; j < MAX_N; j++)
		{
			if(andv & (1 << j)) value += count[j][1];
			if(and_neg & (1 << j)) value += count[j][0];
		}
	}

	int andv = MASK, and_neg = MASK;

	for(int i = 0, j = 0; i < MAX_N && j < MAX_N; i++, j++)
	{
		if(board[i][j] == EMPTY_FIELD) continue;

		andv &= board[i][j];
		and_neg &= (board[i][j]^MASK);
	}

	for(int i = 0; i < MAX_N; i++)
	{
		if(andv & (1 << i)) value += count[i][1];
		if(and_neg & (1 << i)) value += count[i][0];
	}

	andv = MASK, and_neg = MASK;

	for(int i = 0, j = MAX_N - 1; i < MAX_N && j >= 0; i++, j--)
	{
		if(board[i][j] == EMPTY_FIELD) continue;

		andv &= board[i][j];
		and_neg &= (board[i][j] ^ MASK);
	}

	for(int i = 0; i < MAX_N; i++)
	{
		if(andv & (1 << i)) value += count[i][1];
		if(and_neg & (1 << i)) value += count[i][0];
	}

	return value;
}

/*
	Sets move as best
*/
void Bot_Minmax::set_choice(int row, int column, int opponent_piece)
{
	chosen_piece = opponent_piece;
	chosen_board_field.first = row;
	chosen_board_field.second = column;
}

/*
	Analizes potential arrangement of pieces on board using recursive minmax algorithm
	and depending on results chooses the best move
	Maximum depth of algorithm is sets to 2
*/
int Bot_Minmax::minmax(int depth, int piece, int max_depth)
{
	if(depth == max_depth)
	{
		if(depth & 1)
		{
			return MAX_BOARD_VALUE - evaluate(piece);
		}

		else
		{
			return evaluate(piece);
		}
	}

	int max_move = MIN_BOARD_VALUE;
	int min_move = MAX_BOARD_VALUE;
	int evaluated_move;

	for(int row = 0; row < MAX_N; row++)
	{
		for(int column = 0; column < MAX_N; column++)
		{
			if(board[row][column] != EMPTY_FIELD) continue;

			pieces[piece] = false;
			board[row][column] = piece;

			if(is_board_winning())
			{
				if(depth & 1)
				{
					pieces[piece] = true;
					board[row][column] = EMPTY_FIELD;

					return MIN_BOARD_VALUE;
				}

				else
				{
					if(depth == 0)
					{
						set_choice(row,column, EMPTY_FIELD);
					}

					pieces[piece] = true;
					board[row][column] = EMPTY_FIELD;

					return MAX_BOARD_VALUE;
				}
			}

			for(int opponent_piece = 0; opponent_piece < MAX_NUMBER_OF_PIECES; opponent_piece++)
			{
				if(!pieces[opponent_piece]) continue;

				evaluated_move = minmax(depth + 1, opponent_piece, max_depth);

				if(depth == 0)
				{
					if(max_move <= evaluated_move)
					{
						if(max_move == evaluated_move && chosen_board_field.first != -1 && random_int(0,1)) continue;

						max_move = evaluated_move;

						set_choice(row, column, opponent_piece);
					}

					continue;
				}

				max_move = max(max_move, evaluated_move);
				min_move = min(min_move, evaluated_move);
			}

			pieces[piece] = true;
			board[row][column] = EMPTY_FIELD;
		}
	}

	if(depth & 1)
	{
		return min_move;
	}

	else
	{
		return max_move;
	}
}

/*
	Finds the last empty field for the last piece
*/
void Bot_Minmax::last_move()
{
	for(int row = 0; row < MAX_N; row++)
	{
		for(int column = 0; column < MAX_N; column++)
		{
			if(board[row][column] == EMPTY_FIELD)
			{
				set_choice(row, column, EMPTY_FIELD);

				return;
			}
		}
	}
}

/*
	Returns a piece that bot wants to give to the opponent
*/
int Bot_Minmax::get_chosen_piece_type()
{
	pieces[chosen_piece] = false;

	return chosen_piece;
}

/*
	Returns a field where bot wants to place given piece
*/
pair <int, int> Bot_Minmax::get_chosen_board_field()
{
	return chosen_board_field;
}

/*
	Reads board and game difficulty, and launches minmax function to find the best move
*/
void Bot_Minmax::analyze_position(Quarto_game* game, int piece)
{
	board = game->get_board();

	GAME_DIFFICULTY = game->get_game_difficulty_level();

	int pieces_left = 0;

	for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
	{
		pieces[i] = !game->is_piece_used(i);

		if(pieces[i]) pieces_left++;
	}

	chosen_board_field = {-1, -1};

	if(pieces_left == 0)
	{
		last_move();
	}

	else
	{
		minmax(0, piece, min(2, pieces_left));
	}
}