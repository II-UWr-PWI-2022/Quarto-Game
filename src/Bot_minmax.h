#ifndef BOT_MINMAX_H
#define BOT_MINMAX_H

#include "Libraries_And_Macros.h"
#include "Quarto_game.h"

class Bot_Minmax
{
	vector <vector <int>> board = vector <vector <int>> (MAX_N, vector <int> (MAX_N));
    vector <bool> pieces = vector <bool> (MAX_NUMBER_OF_PIECES, true);

    bool is_line_winning(char p1, char p2, char p3, char p4);
    bool is_board_winning();
    int evaluate(int piece);
    int minmax(int depth,int piece,int max_depth);
    pair<int,int> chosen_board_field = {0, 0};
    int chosen_piece = 0;
    const int EMPTY = 16;
    const int MAX_BOARD_VALUE = 650;
    const int MIN_BOARD_VALUE = 0;
public:
    int get_chosen_piece_type();
    pair <int, int> get_chosen_board_field();
    void analyze_position(Quarto_game* game, int piece);
};

#endif //EMPTY_BOT_H