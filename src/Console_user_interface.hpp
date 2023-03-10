#ifndef CONSOLE_USER_INTERFACE_H
#define CONSOLE_USER_INTERFACE_H

#include "Libraries_and_macros.hpp"
#include "Quarto_game.hpp"
#include "Bot_random.hpp"
#include "Bot_minmax.hpp"
#include "Bot_superior.hpp"
#include "Player.hpp"
#include "DB_manager.hpp"
#include <time.h>

class Console_user_interface
{
private:
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

	Bot_Random* bot_random_1;
	Bot_Random* bot_random_2;

	Bot_Minmax* bot_minmax_1;
	Bot_Minmax* bot_minmax_2;

	Bot_Superior *bot_superior_1;
	Bot_Superior *bot_superior_2;

	DB_manager db_manager;
	Player user;

	const string PATH = "../db/users.xml";

	char get_single_character();
	char select_from_main_menu();   // dodanie rekordu 3
	char select_from_player_menu(char player);  //
	void start_game(bool game_difficulty_level);    // Rozgrywka
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

	void display_ranking();
	void account_settings();
	void assign_points(int game_status);

public:
	Console_user_interface();
	void display_main_menu(); // Wyswietlanie opcji
};

#endif // CONSOLE_USER_INTERFACE_H