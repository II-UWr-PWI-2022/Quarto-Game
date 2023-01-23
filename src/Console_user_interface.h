#ifndef CONSOLE_USER_INTERFACE_H
#define CONSOLE_USER_INTERFACE_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"
#include "Bot_random.h"
#include "Bot_minmax.h"
#include "Bot_superior.h"
// #include "Bot_template.h"

class Console_user_interface
{
    vector <vector <string>> board = vector <vector <string>> (MAX_N, vector <string> (MAX_N));

    /*
    Marks are used to show the winning pattern on the board,
    they consists of lines displayed over and under the
    piece symbol. Lines consists of dashes. If piece is not in winning pattern
    or field is empty, spaces are displayed instead of dashes - marks are invisible.
    */
    vector <vector <string>> marks = vector <vector <string>> (MAX_N, vector <string> (MAX_N));
    vector <string> free_pieces = vector <string> (MAX_NUMBER_OF_PIECES);
    Quarto_game* game;

	/*
		index = 0 -> human
		index = 1 -> bot_1
		index = 2 -> bot_2
		index = 3 -> bot_3
	*/

	int index_player_A;
	int index_player_B;

	Bot_Random bot_random_1;
	Bot_Random bot_random_2;

	Bot_Minmax bot_minmax_1;
	Bot_Minmax bot_minmax_2;

    Bot_Superior bot_superior_1;
    Bot_Superior bot_superior_2;

    char get_single_character();
    char select_from_main_menu();
    char select_from_player_menu(char player);
    void start_game(bool game_difficulty_level);
    void clear_marks();
    void update_marks();
    string create_piece_symbol(int type);
    void update_board();
    void display_the_board();
    string create_symbol_of_free_piece(int number_of_piece);
    void update_free_pieces();
    void display_free_pieces();
    string get_piece_symbol_from_user();
    int change_piece_symbol_to_type(string symbol);
    int find_piece_number(string symbol);
    int make_move();
    int display_player_menu(char player);

public:
    Console_user_interface();
    void display_main_menu();
};

#endif // CONSOLE_USER_INTERFACE_H
