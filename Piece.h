#ifndef PIECE_H
#define PIECE_H

using namespace std;

class Piece
{
    char type;
    bool isAlreadyUsed;

public:
    Piece(int pieceType);
    //~Piece();
    void setPieceAsUsed();
    bool isPieceUsed();
    char getPieceType();
};

#endif // PIECE_H
