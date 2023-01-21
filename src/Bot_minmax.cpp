#include "Bot_minmax.h"

bool Bot::is_line_winning(char p1, char p2, char p3, char p4)
{
    if ((p1|p2|p3|p4)&(1<<4)) return false;
    char mask = (1<<4)-1;
    return (((p1&p2&p3&p4&mask)>0) || (((p1^mask)&(p2^mask)&(p3^mask)&(p4^mask)&mask)>0));
}


bool Bot::is_board_winning()
{
    for (int i = 0; i < 4; i++)
    {
        if (is_line_winning(board[i][0], board[i][1], board[i][2], board[i][3])) return true;
    }
    for (int i = 0; i < 4; i++)
    {
        if (is_line_winning(board[0][i], board[1][i], board[2][i], board[3][i])) return true;
    }
    return (is_line_winning(board[0][0], board[1][1], board[2][2], board[3][3])
        || is_line_winning(board[0][3], board[1][2], board[2][1], board[3][0]));
}

int Bot::evaluate(int piece)
{
    int value = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = piece;
                if (is_board_winning()) value = MAX_BOARD_VALUE;
                board[i][j] = EMPTY;
            }
        }
    }
    if (value == MAX_BOARD_VALUE) return value;

    int count[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
    for (int piece = 0; piece <16; piece++)
    {
        if (pieces[piece] == false) continue;
        for (int i = 0; i < 4; i++)
        {
            count[i][((piece&(1<<i))>0)]++;
        }
    }

    int mask = (1<<4)-1;
    for (int i = 0; i < 4; i++)
    {
        int andv = mask, and_neg = mask;
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == EMPTY) continue;
            andv &= board[i][j];
            and_neg &= (board[i][j]^mask);
        }
        for (int j = 0; j < 4; j++)
        {
            if (andv&(1<<j)) value += count[j][1];
            if (and_neg&(1<<j)) value += count[j][0];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int andv = mask, and_neg = mask;
        for (int j = 0; j < 4; j++)
        {
            if (board[j][i] == EMPTY) continue;
            andv &= board[j][i];
            and_neg &= (board[j][i]^mask);
        }
        for (int j = 0; j < 4; j++)
        {
            if (andv&(1<<j)) value += count[j][1];
            if (and_neg&(1<<j)) value += count[j][0];
        }
    }
    int andv = mask, and_neg = mask;
    for (int i = 0, j = 0; i < 4 && j < 4; i++, j++)
    {
        if (board[i][j] == EMPTY) continue;
        andv &= board[i][j];
        and_neg &= (board[i][j]^mask);
    }
    for (int j = 0; j < 4; j++)
    {
        if (andv&(1<<j)) value += count[j][1];
        if (and_neg&(1<<j)) value += count[j][0];
    }
    andv = mask, and_neg = mask;
    for (int i = 0, j = 3; i < 4 && j >= 0; i++, j--)
    {
        if (board[i][j] == EMPTY) continue;
        andv &= board[i][j];
        and_neg &= (board[i][j]^mask);
    }
    for (int j = 0; j < 4; j++)
    {
        if (andv&(1<<j)) value += count[j][1];
        if (and_neg&(1<<j)) value += count[j][0];
    }
    return value;
}

void Bot::set_choice(int row, int column, int opponent_piece)
{
    ans_piece=opponent_piece;
    ans_board_field.first=row;
    ans_board_field.second=column;
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
                    pieces[piece] = true;
                    board[row][column] = EMPTY;
                    return MIN_BOARD_VALUE;
                }
                else
                {
                    if (depth==0)
                    {
                        set_choice(row,column,10);
                    }
                    pieces[piece] = true;
                    board[row][column] = EMPTY;
                    return MAX_BOARD_VALUE;
                }
            }
            for(int opponent_piece=0;opponent_piece<16;opponent_piece++)
            {
                if(!pieces[opponent_piece]) continue;
                evaluated_move=minmax(depth+1,opponent_piece,max_depth);
                if(depth==0)
                {
                    if(max_move<=evaluated_move)
                    {
                        max_move=evaluated_move;
                        set_choice(row, column, opponent_piece);
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
    pieces[ans_piece] = false;
    return ans_piece;
}

pair<int,int> Bot::get_board_field(Quarto_game *game,int piece)
{
    for(int row=0;row<4;row++)
    {
        for(int column=0;column<4;column++)
        {
            board[row][column] = (game->get_piece_type_from_board_field(row,column));
        }
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    minmax(0,piece,2);
    pieces[piece]=false;
    return ans_board_field;
}