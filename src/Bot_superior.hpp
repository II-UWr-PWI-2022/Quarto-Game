#ifndef BOT_SUPERIOR_H
#define BOT_SUPERIOR_H

#include "Libraries_and_macros.hpp"
#include "Quarto_game.hpp"

class Bot_Superior
{
private:
	const int MAX_BOARD_VALUE = 18;
	const int MIN_BOARD_VALUE = 0;

	vector <vector <int>> board = vector <vector <int>> (MAX_N, vector <int> (MAX_N));
	vector <bool> pieces = vector <bool> (MAX_NUMBER_OF_PIECES, true);

	pair<int,int> chosen_board_field = {0, 0};
	int chosen_piece = 0;

	bool GAME_DIFFICULTY;

	bool is_pattern_winning(int p1, int p2, int p3, int p4);
	bool is_board_winning();
	bool is_triple(int given_piece, vector <int> pattern);
	int evaluate(int piece);
	int minmax(int depth, int piece, int max_depth);
	int random_int(int L, int R);
	void last_move();
	void set_choice(int row, int column, int opponent_piece);

public:
	int get_chosen_piece_type();
	pair <int, int> get_chosen_board_field();
	void analyze_position(Quarto_game* game, int piece);
};

#endif