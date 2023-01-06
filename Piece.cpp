#include "Piece.h"

/*
Constructor. It takes as an argument an integer from 0 to 15
and sets bits depending on piece characteristics.
Each piece has four characteristics determined by bits
set at 1 according to the below list:
    - color: dark (1st bit) or light (2nd bit),
    - shape: round (3rd bit) or square (4th bit),
    - height: tall (5th bit) or short (6th bit),
    - texture: solid (7th bit) or hollow (8th bit).
Pieces are collected in table of pieces in object of Quarto game class,,
in the below list given are piece types corresponding to index number
in the table of pieces which is given as an constructor argument:
    - 0 - DRTS,
    - 1 - DRTH,
    - 2 - DRSS,
    - 3 - DRSH,
    - 4 - DSTS,
    - 5 - DSTH,
    - 6 - DSSS,
    - 7 - DSSH,
    - 8 - LRTS,
    - 9 - LRTH,
    - 10 - LRSS,
    - 11 - LRSH,
    - 12 - LSTS,
    - 13 - LSTH,
    - 14 - LSSS,
    - 15 - LSSH.
*/
Piece::Piece(int piece_type)
{
    type = 0;
    is_already_used = false;

    //color
    if (piece_type < 8)
    {
        type = type | 1 << 0;
    }
    else
    {
        type = type | 1 << 1;
    }

    //shape
    if (piece_type % 8 < 4)
    {
        type = type | 1 << 2;
    }
    else
    {
        type = type | 1 << 3;
    }

    //height
    if (piece_type % 4 < 2)
    {
        type = type | 1 << 4;
    }
    else
    {
        type = type | 1 << 5;
    }

    //texture
    if (piece_type % 2 < 1)
    {
        type = type | 1 << 6;
    }
    else
    {
        type = type | 1 << 7;
    }
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
    if (is_already_used) return true;
    else return false;
}

/*
Informs what is the piece type.
*/
char Piece::get_piece_type()
{
    return type;
}
