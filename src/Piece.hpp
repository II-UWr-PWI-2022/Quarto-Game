#ifndef PIECE_H
#define PIECE_H

#include "Libraries_and_macros.hpp"

class Piece
{
private:
	int type;
	bool is_already_used;

public:
	void initialization(int piece_type);
	void set_piece_as_used();
	bool is_piece_used();
	int get_piece_type();
};

#endif // PIECE_H
