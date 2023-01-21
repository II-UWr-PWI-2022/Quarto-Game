#include "Bot_template.h"

int Bot::get_chosen_piece_type()
{
    return ans_piece;
}

pair<int,int> Bot::get_chosen_board_field(Quarto_game *game,int piece)
{
    for(int row=0;row<4;row++)
    {
        for(int column=0;column<4;column++)
        {
            board[row][column] = game->get_piece_type_from_board_field(row,column);
        }
    }
    ans_board_field={0,0};
    ans_piece=0;
    return ans_board_field;
}