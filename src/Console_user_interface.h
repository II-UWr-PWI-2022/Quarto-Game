#ifndef CONSOLE_USER_INTERFACE_H
#define CONSOLE_USER_INTERFACE_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"
#include "Bot_minmax.h"

class Console_user_interface
{
    string board[MAX_N][MAX_N];

    /*
    Marks are used to show the winning pattern on the board,
    they consists of lines displayed over and under the
    piece symbol. Lines consists of dashes. If piece is not in winning pattern
    or field is empty, spaces are displayed instead of dashes - marks are invisible.
    */
    string marks[MAX_N][MAX_N];
    string free_pieces[MAX_NUMBER_OF_PIECES];
    Quarto_game *game;

    char get_single_character();
    char select_from_main_menu();
    void start_game(bool game_difficulty_level);
    void clear_marks();
    void update_marks();
    string create_piece_symbol(char type);
    void update_board();
    void display_the_board();
    string create_symbol_of_free_piece(int number_of_piece);
    void update_free_pieces();
    void display_free_pieces();
    string get_piece_symbol_from_user();
    char change_piece_symbol_to_type(string symbol);
    int find_piece_number(string symbol);
    int make_move(Bot bot);

public:
    Console_user_interface();
    void display_main_menu();
};

#endif // CONSOLE_USER_INTERFACE_H