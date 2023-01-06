#include "QuartoGame.h"
#include <iostream>

/*
Constructor. It takes as an argument a bool variable.
If the value of argument is true, the game is played in
hard mode, if it is false - in easy mode.
*/
QuartoGame::QuartoGame(bool gameDifficultyLevel)
    : DIFFICULTY_LEVEL(gameDifficultyLevel)
{
    playerActive = 0;
    numberOfUsedPieces = 0;
}


QuartoGame::~QuartoGame()
{
    cout << "game destructor"<<endl;
}

/*
Checks if particular piece from table of pieces in
Quarto game object has been used.
*/
bool QuartoGame::isPieceUsed(int numberOfPiece)
{
    return pieces[numberOfPiece].isPieceUsed();
}

/*
Checks if particular field on board is free.
*/
bool QuartoGame::isBoardFieldFree(int row, int column)
{
    if (board[row][column] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
Checks if on particular field of board is located
one of pieces forming a winning pattern.
*/
bool QuartoGame::getWinningPatternField(int row, int column)
{
    return winningPattern[row][column];
}

/*
Returns the type of piece defined by its index number
in table of pieces in Quarto game object.
*/
char QuartoGame::getPieceType(int numberOfPiece)
{
    return pieces[numberOfPiece].getPieceType();
}

/*
Returns true when player B is active and false when it is player A.
Active player is the one making move.
*/
bool QuartoGame::getPlayerActive()
{
    return playerActive;
}

/*
Returns the vale of piece which is located on the board
field specified by row and column number.
*/
char QuartoGame::getPieceTypeFromBoardField(int row, int column)
{
    return board[row][column];
}

/*
Returns the number of index in table of pieces in Quarto game
object for piece defined by its type.
*/
int QuartoGame::findPieceNumber(char typeOfPiece)
{
    int pieceNumber = 100;
    for (int i = 0; i < 16; i++)
    {
        if (pieces[i].getPieceType() == typeOfPiece)
        {
            if (pieces[i].isPieceUsed() == false)
            {
                pieceNumber = i;
            }
            break;
        }
    }
    return pieceNumber;
}
