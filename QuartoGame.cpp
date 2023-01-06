#include "QuartoGame.h"

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

/*
QuartoGame::~QuartoGame()
{
    cout << "game destructor"<<endl;
}
*/

/*
Search for type of piece defined by its number in table of pieces in
Quarto game object. Then this value is assigned to the field in the
board specified by row and column number.
*/
void QuartoGame::putPieceOnBoard(int row, int column, int pieceNumber)
{
    board[row][column] = pieces[pieceNumber].getPieceType();
    pieces[pieceNumber].setPieceAsUsed();
    numberOfUsedPieces++;
}

/*
Sets the value of active player to the opposite.
*/
void QuartoGame::changePlayer()
{
    playerActive = !playerActive;
}

/*
Checks, in easy mode, by using bit operations if after las move
are there four pieces on appropriate fields, which have the same
value of at least one characteristic. If yes, it sets the winning
pattern and returns true, it nor - it returns false.
*/
bool QuartoGame::isGameFinishedInEasyVersion(int row, int column)
{
    if ((board[row][0]&board[row][1]&board[row][2]&board[row][3]) != 0)
    {
        winningPattern[row][0] = 1;
        winningPattern[row][1] = 1;
        winningPattern[row][2] = 1;
        winningPattern[row][3] = 1;
        return true;
    }
    else if ((board[0][column]&board[1][column]&board[2][column]&board[3][column]) != 0)
    {
        winningPattern[0][column] = 1;
        winningPattern[1][column] = 1;
        winningPattern[2][column] = 1;
        winningPattern[3][column] = 1;
        return true;
    }
    else if ((board[0][0]&board[1][1]&board[2][2]&board[3][3]) != 0)
    {
        winningPattern[0][0] = 1;
        winningPattern[1][1] = 1;
        winningPattern[2][2] = 1;
        winningPattern[3][3] = 1;
        return true;
    }
    else if ((board[3][0]&board[2][1]&board[1][2]&board[0][3]) != 0)
    {
        winningPattern[3][0] = 1;
        winningPattern[2][1] = 1;
        winningPattern[1][2] = 1;
        winningPattern[0][3] = 1;
        return true;
    }
    else return false;
}

/*
Checks, in hard mode, by using bit operations if after las move
are there four pieces on appropriate fields, which have the same
value of at least one characteristic. If yes, it sets the winning
pattern and returns true, it nor - it returns false.
*/
bool QuartoGame::isGameFinishedInHardVersion(int row, int column)
{
    if (column < 3 && row < 3)
    {
        if ((board[row][column]&board[row][column+1]&board[row+1][column+1]&board[row+1][column]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row][column+1] = 1;
            winningPattern[row+1][column+1] = 1;
            winningPattern[row+1][column] = 1;
            return true;
        }
    }
    if (column > 0 && row < 3)
    {
        if ((board[row][column]&board[row+1][column]&board[row+1][column-1]&board[row][column-1]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row+1][column] = 1;
            winningPattern[row+1][column-1] = 1;
            winningPattern[row][column-1] = 1;
            return true;
        }
    }
    if (column > 0 && row > 0)
    {
        if ((board[row][column]&board[row][column-1]&board[row-1][column-1]&board[row-1][column]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row][column-1] = 1;
            winningPattern[row-1][column-1] = 1;
            winningPattern[row-1][column] = 1;
            return true;
        }
    }
    if (column < 3 && row > 0)
    {
        if ((board[row][column]&board[row-1][column]&board[row-1][column+1]&board[row][column+1]) != 0)
        {
            winningPattern[row][column] = 1;
            winningPattern[row-1][column] = 1;
            winningPattern[row-1][column+1] = 1;
            winningPattern[row][column+1] = 1;
            return true;
        }
    }
    return false;
}

/*
Puts piece on board, then checks if are there any winning pattern and game is finished,
if yes it returns different value depending on the player making the last move, if not
it checks how many pieces have been used and if there is draw, if not it changes the
active user and returns 0.
*/
int QuartoGame::makeMove(int row, int column, int pieceNumber)
{
    putPieceOnBoard(row,column,pieceNumber);
    bool isFinished;
    int result = 0;

    if (DIFFICULTY_LEVEL)
    {
        isFinished = isGameFinishedInHardVersion(row,column);
    }
    else
    {
        isFinished = isGameFinishedInEasyVersion(row,column);
    }

    if (isFinished)
    {
        if (playerActive)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }
    }
    else if (numberOfUsedPieces == 16)
    {
        result = 3;
    }
    else
    {
        changePlayer();
    }
    return result;
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



