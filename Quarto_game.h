#ifndef QUARTO_GAME_H
#define QUARTO_GAME_H

#include "Piece.h"

using namespace std;

class Quarto_game
{
    char board[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    Piece pieces[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    bool winning_pattern[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    const bool DIFFICULTY_LEVEL; // game difficulty version (0 is easy, 1 is hard)
    bool player_active; // player making a move (0 is player A, 1 is player B)
    int number_of_used_pieces;

    void put_piece_on_board(int row, int column, int piece_number);
    void change_player();
    bool is_game_finished_in_easy_version(int row, int column);
    bool is_game_finished_in_hard_version(int row, int column);

public:
    Quarto_game(bool game_difficulty_level);
    int make_move(int row, int column, int piece_number);

    bool is_piece_used(int number_of_piece);
    bool is_board_field_free(int row, int column);
    bool get_winning_pattern_field(int row, int column);
    char get_piece_type(int number_of_piece);
    bool get_player_active();
    char get_piece_type_from_board_field(int row, int column);
    int find_piece_number(char type_of_piece);
};

#endif // QUARTO_GAME_H
