#include "Piece.h"

/*
This is function is a constructor of "Piece" class. It takes as an argument an integer from 0 to 15 and sets bits
according to piece characteristics.
Each piece has four characteristics determined by bits set at 1 according to the below list:
    - color: dark (1st bit) or light (2nd bit),
    - shape: round (3rd bit) or square (4th bit),
    - height: tall (5th bit) or short (6th bit),
    - texture: solid (7th bit) or hollow (8th bit).
Pieces are collected in table "pieces" in object "game" of class "QuartoGame", in the below list given are piece types
corresponding to each position in the table - position in table "pieces" is equal to "type" argument
of "Piece" constructor:
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
Piece::Piece(int pieceType)
{
    type = 0;
    isAlreadyUsed = false;

    //color
    if (pieceType < 8)
    {
        type = type | 1 << 0;
    }
    else
    {
        type = type | 1 << 1;
    }

    //shape
    if (pieceType % 8 < 4)
    {
        type = type | 1 << 2;
    }
    else
    {
        type = type | 1 << 3;
    }

    //height
    if (pieceType % 4 < 2)
    {
        type = type | 1 << 4;
    }
    else
    {
        type = type | 1 << 5;
    }

    //texture
    if (pieceType % 2 < 1)
    {
        type = type | 1 << 6;
    }
    else
    {
        type = type | 1 << 7;
    }
}

/*
Piece::~Piece()
{
    cout << "piece destructor" << type << endl;
}
*/

/*
This function sets the private variable "isAlreadyUsed" to true, when piece is chosen and put
on the game board by the object of class "QuartoGame'.
*/
void Piece::setPieceAsUsed()
{
    isAlreadyUsed = true;
}

/*
This function return the value of private variable "isAlreadyUsed".
*/
bool Piece::isPieceUsed()
{
    if (isAlreadyUsed) return true;
    else return false;
}

/*
This function return the value of private variable "type".
*/
char Piece::getPieceType()
{
    return type;
}
