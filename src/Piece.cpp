#include "Piece.hpp"

/*
	Constructor. It takes as an argument an integer from 0 to 15
	Each piece has four characteristics determined by bits
	set at 1 or 0 according to the below list:
		- color: dark (0th bit set at 1) or light (0th bit set at 0),
		- shape: round (1st bit set at 1) or square (1st bit set at 0),
		- height: tall (2nd bit set at 1) or short (2nd bit set at 0),
		- texture: solid (3rd bit set at 1) or hollow (3rd bit set at 0).
	Pieces are collected in table of pieces in object of Quarto game class,
	in the below list given are piece types corresponding to index number
	in the table of pieces which is given as an constructor argument:
		- number:  0, bits from 0 to 3: 0000 symbol: LSSH,
		- number:  1, bits from 0 to 3: 0001 symbol: DSSH,
		- number:  2, bits from 0 to 3: 0010 symbol: LRSH,
		- number:  3, bits from 0 to 3: 0011 symbol: DRSH,
		- number:  4, bits from 0 to 3: 0100 symbol: LSTH,
		- number:  5, bits from 0 to 3: 0101 symbol: DSTH,
		- number:  6, bits from 0 to 3: 0110 symbol: LRTH,
		- number:  7, bits from 0 to 3: 0111 symbol: DRTH,
		- number:  8, bits from 0 to 3: 1000 symbol: LSSS,
		- number:  9, bits from 0 to 3: 1001 symbol: DSSS,
		- number: 10, bits from 0 to 3: 1010 symbol: LRSS,
		- number: 11, bits from 0 to 3: 1011 symbol: DRSS,
		- number: 12, bits from 0 to 3: 1100 symbol: LSTS,
		- number: 13, bits from 0 to 3: 1101 symbol: DSTS,
		- number: 14, bits from 0 to 3: 1110 symbol: LRTS,
		- number: 15, bits from 0 to 3: 1111 symbol: DRTS.
*/

void Piece::initialization(int piece_type)
{
	type = piece_type;
	is_already_used = false;
}

/*
	Sets the piece as used.
*/
void Piece::set_piece_as_used()
{
	is_already_used = true;
}

/*
	Informs whether the piece has already been used.
*/
bool Piece::is_piece_used()
{
	if(is_already_used)
	{
		return true;
	}

	else
	{
		return false;
	}
}

/*
	Informs what is the piece type.
*/
int Piece::get_piece_type()
{
	return type;
}
