#ifndef QUARTOGAME_H
#define QUARTOGAME_H

#include "Piece.h"

using namespace std;

class QuartoGame
{
    char board[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    Piece pieces[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    bool winningPattern[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    const bool DIFFICULTY_LEVEL; // game difficulty version (0 is easy, 1 is hard)
    bool playerActive; // player making a move (0 is player A, 1 is player B)
    int numberOfUsedPieces;

    void putPieceOnBoard(int row, int column, int pieceNumber);
    void changePlayer();
    bool isGameFinishedInEasyVersion(int row, int column);
    bool isGameFinishedInHardVersion(int row, int column);

public:
    QuartoGame(bool gameDifficultyLevel);
    //~QuartoGame();
    int makeMove(int row, int column, int pieceNumber);

    bool isPieceUsed(int numberOfPiece);
    bool isBoardFieldFree(int row, int column);
    bool getWinningPatternField(int row, int column);
    char getPieceType(int numberOfPiece);
    bool getPlayerActive();
    char getPieceTypeFromBoardField(int row, int column);
    int findPieceNumber(char typeOfPiece);
};

#endif // QUARTOGAME_H
