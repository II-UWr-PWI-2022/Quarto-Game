#include "Quarto_game.h"

/*
Constructor. It takes as an argument a bool variable.
If the value of argument is true, the game is played in
hard mode, if it is false - in easy mode.
*/
Quarto_game::Quarto_game(bool game_difficulty_level)
    : DIFFICULTY_LEVEL(game_difficulty_level)
{
	for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
	{
		pieces[i].initialization(i);
	}

    player_active = 0;
    number_of_used_pieces = 0;
}

/*
Search for type of piece defined by its number in table of pieces in
Quarto game object. Then this value is assigned to the field in the
board specified by row and column number.
*/
void Quarto_game::put_piece_on_board(int row, int column, int piece_number)
{
    board[row][column] = pieces[piece_number].get_piece_type();
    pieces[piece_number].set_piece_as_used();
    number_of_used_pieces++;
}

/*
Sets the value of active player to the opposite.
*/
void Quarto_game::change_player()
{
    player_active = !player_active;
}

/*
Checks, in easy mode, by using bit operations if after last move
are there four pieces on appropriate fields, which have the same
value of at least one characteristic. If yes, it sets the winning
pattern and returns true, it not - it returns false.
*/
bool Quarto_game::is_game_finished_in_easy_version(int row, int column)
{
    if(board[row][0] != EMPTY_FIELD && board[row][1] != EMPTY_FIELD && board[row][2] != EMPTY_FIELD && board[row][3] != EMPTY_FIELD
		&& ((board[row][0] & board[row][1] & board[row][2] & board[row][3])
		|| (~(board[row][0] | board[row][1] | board[row][2] | board[row][3]) & MASK)))
    {
        winning_pattern[row][0] = true;
        winning_pattern[row][1] = true;
        winning_pattern[row][2] = true;
        winning_pattern[row][3] = true;

        return true;
    }

    if(board[0][column] != EMPTY_FIELD && board[1][column] != EMPTY_FIELD && board[2][column] != EMPTY_FIELD && board[3][column] != EMPTY_FIELD
		&& ((board[0][column] & board[1][column] & board[2][column] & board[3][column])
		|| (~(board[0][column] | board[1][column] | board[2][column] | board[3][column]) & MASK)))
    {
        winning_pattern[0][column] = true;
        winning_pattern[1][column] = true;
        winning_pattern[2][column] = true;
        winning_pattern[3][column] = true;

        return true;
    }

    if(board[0][0] != EMPTY_FIELD && board[1][1] != EMPTY_FIELD && board[2][2] != EMPTY_FIELD && board[3][3] != EMPTY_FIELD
		&& ((board[0][0] & board[1][1] & board[2][2] & board[3][3])
		|| (~(board[0][0] | board[1][1] | board[2][2] | board[3][3]) & MASK)))
    {
        winning_pattern[0][0] = true;
        winning_pattern[1][1] = true;
        winning_pattern[2][2] = true;
        winning_pattern[3][3] = true;

        return true;
    }

    if(board[3][0] != EMPTY_FIELD && board[2][1] != EMPTY_FIELD && board[1][2] != EMPTY_FIELD && board[0][3] != EMPTY_FIELD
		&& ((board[3][0] & board[2][1] & board[1][2] & board[0][3])
		|| (~(board[3][0] | board[2][1] | board[1][2] | board[0][3]) & MASK)))
    {
        winning_pattern[3][0] = true;
        winning_pattern[2][1] = true;
        winning_pattern[1][2] = true;
        winning_pattern[0][3] = true;

        return true;
    }

	return false;
}

/*
Checks, in hard mode, by using bit operations if after last move
are there four pieces on appropriate fields, which have the same
value of at least one characteristic. If yes, it sets the winning
pattern and returns true, it not - it returns false.
*/
bool Quarto_game::is_game_finished_in_hard_version(int row, int column)
{
    if(column < 3 && row < 3)
    {
        if(board[row][column] != EMPTY_FIELD && board[row][column+1] != EMPTY_FIELD && board[row+1][column+1] != EMPTY_FIELD && board[row+1][column] != EMPTY_FIELD
			&& ((board[row][column] & board[row][column+1] & board[row+1][column+1] & board[row+1][column])
			|| (~(board[row][column] | board[row][column+1] | board[row+1][column+1] | board[row+1][column]) & MASK)))
        {
            winning_pattern[row][column] = true;
            winning_pattern[row][column+1] = true;
            winning_pattern[row+1][column+1] = true;
            winning_pattern[row+1][column] = true;

            return true;
        }
    }

    if(column > 0 && row < 3)
    {
        if(board[row][column] != EMPTY_FIELD && board[row+1][column] != EMPTY_FIELD && board[row+1][column-1] != EMPTY_FIELD && board[row][column-1] != EMPTY_FIELD
			&& ((board[row][column] & board[row+1][column] & board[row+1][column-1] & board[row][column-1])
			|| (~(board[row][column] | board[row+1][column] | board[row+1][column-1] | board[row][column-1]) & MASK)))
        {
            winning_pattern[row][column] = true;
            winning_pattern[row+1][column] = true;
            winning_pattern[row+1][column-1] = true;
            winning_pattern[row][column-1] = true;

            return true;
        }
    }

    if(column > 0 && row > 0)
    {
        if(board[row][column] != EMPTY_FIELD && board[row][column-1] != EMPTY_FIELD && board[row-1][column-1] != EMPTY_FIELD && board[row+1][column] != EMPTY_FIELD
			&& ((board[row][column] & board[row][column-1] & board[row-1][column-1] & board[row+1][column])
			|| (~(board[row][column] | board[row][column-1] | board[row-1][column-1] | board[row+1][column]) & MASK)))
        {
            winning_pattern[row][column] = true;
            winning_pattern[row][column-1] = true;
            winning_pattern[row-1][column-1] = true;
            winning_pattern[row-1][column] = true;

            return true;
        }
    }

    if(column < 3 && row > 0)
    {
        if(board[row][column] != EMPTY_FIELD && board[row-1][column] != EMPTY_FIELD && board[row-1][column+1] != EMPTY_FIELD && board[row][column+1] != EMPTY_FIELD
			&& ((board[row][column] & board[row-1][column] & board[row-1][column+1] & board[row][column+1])
			|| (~(board[row][column] | board[row-1][column] | board[row-1][column+1] | board[row][column+1]) & MASK)))
        {
            winning_pattern[row][column] = true;
            winning_pattern[row-1][column] = true;
            winning_pattern[row-1][column+1] = true;
            winning_pattern[row][column+1] = true;

            return true;
        }
    }

    return false;
}

/*
Puts piece on board, then checks if there are any winning pattern and game is finished,
if yes it returns different value depending on the player making the last move, if not
it checks how many pieces have been used and if there is draw, if not it changes the
active user and returns 0.
*/
int Quarto_game::make_move(int row, int column, int piece_number)
{
    put_piece_on_board(row,column,piece_number);
    bool is_finished;
    int result = 0;

    if(DIFFICULTY_LEVEL)
    {
        is_finished = is_game_finished_in_hard_version(row,column);
    }

    else
    {
        is_finished = is_game_finished_in_easy_version(row,column);
    }

    if(is_finished)
    {
        if(player_active)
        {
            result = 2;
        }

        else
        {
            result = 1;
        }
    }

    else if(number_of_used_pieces == MAX_NUMBER_OF_PIECES)
    {
        result = 3;
    }

    else
    {
        change_player();
    }

    return result;
}

/*
Checks if particular piece from table of pieces in
Quarto game object has been used.
*/
bool Quarto_game::is_piece_used(int number_of_piece)
{
    return pieces[number_of_piece].is_piece_used();
}

/*
Checks if particular field on board is free.
*/
bool Quarto_game::is_board_field_free(int row, int column)
{
    if(board[row][column] == EMPTY_FIELD)
    {
        return true;
    }

    else
    {
        return false;
    }
}

/*
Checks if on particular field of board is located
one of pieces forming a winning pattern.
*/
bool Quarto_game::get_winning_pattern_field(int row, int column)
{
    return winning_pattern[row][column];
}

/*
Returns the type of piece defined by its index number
in table of pieces in Quarto game object.
*/
int Quarto_game::get_piece_type(int number_of_piece)
{
    return pieces[number_of_piece].get_piece_type();
}

/*
Returns true when player B is active and false when it is player A.
Active player is the one making move.
*/
bool Quarto_game::get_player_active()
{
    return player_active;
}

/*
Returns the value of piece which is located on the board
field specified by row and column number.
*/
int Quarto_game::get_piece_type_from_board_field(int row, int column)
{
    return board[row][column];
}

/*
Returns the number of index in table of pieces in Quarto game
object for piece defined by its type.
*/
int Quarto_game::find_piece_number(int type_of_piece)
{
    int piece_number = 100;

    for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
    {
        if(pieces[i].get_piece_type() == type_of_piece)
        {
            if(pieces[i].is_piece_used() == false)
            {
                piece_number = i;
            }

            break;
        }
    }

    return piece_number;
}

bool Quarto_game::get_game_difficulty_level()
{
	return DIFFICULTY_LEVEL;
}