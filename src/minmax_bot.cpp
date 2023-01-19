#include "minmax_bot.h"

int Bot::evaluate(int piece){

}

bool Bot::is_board_winning(){

}

int Bot::minmax(int depth, int piece, int max_depth)
{
    if(depth==max_depth)
    {
        if(depth&1)
        {
            return MAX_BOARD_VALUE-evaluate(piece);
        } 
        else 
        {
            return evaluate(piece);
        }
    }
    int max_move=MIN_BOARD_VALUE;
    int min_move=MAX_BOARD_VALUE;
    int evaluated_move;
    for(int row=0;row<4;row++)
    {
        for(int column=0;column<4;column++)
        {
            if(board[row][column]!=EMPTY) continue;
            pieces[piece]=false;
            board[row][column]=piece;
            if(is_board_winning())
            {
                if(depth&1)
                {
                    return MIN_BOARD_VALUE;
                } 
                else 
                {
                    return MAX_BOARD_VALUE;
                }
            }
            for(int opponent_piece=0;opponent_piece<16;piece++)
            {
                if(!pieces[piece]) continue;
                evaluated_move=minmax(depth+1,opponent_piece,max_depth);
                if(depth==0)
                {
                    if(max_move<evaluated_move)
                    {
                        max_move=evaluated_move;
                        ans_piece=piece;
                        ans_board_field.first=row;
                        ans_board_field.second=column;
                    }
                    continue;
                }
                max_move=max(max_move,evaluated_move);
                min_move=min(min_move,evaluated_move);
            }
            pieces[piece]=true;
            board[row][column]=EMPTY;
        }
    }
    if(depth&1)
    {
        return min_move;
    } 
    else 
    {
        return max_move;
    }
}


int Bot::get_piece_type()
{
    return ans_piece;
}

pair<int,int> Bot::get_board_field(Quarto_game *game,int piece)
{
    for(int row=0;row<4;row++)
    {
        for(int column=0;column<4;column++)
        {   
            board[row][column] = game->get_piece_type_from_board_field(row,column);
        }
    }
    minmax(0,piece,2);
    pieces[piece]=false;
    pieces[ans_piece]=false;
    return ans_board_field;
}