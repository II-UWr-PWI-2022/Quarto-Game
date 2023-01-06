#ifndef CONSOLEUSERINTERFACE_H
#define CONSOLEUSERINTERFACE_H

#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "QuartoGame.h"

using namespace std;

class ConsoleUserInterface
{
    string board[4][4];

    /*
    Marks are used to show the winning pattern on the board,
    they consists of lines displayed over and under the
    piece symbol. Lines consists of dashes. If piece is not in winning pattern
    or field is empty, spaces are displayed instead of dashes - marks are invisible.
    */
    string marks[4][4];
    string freePieces[16];
    QuartoGame *game;

    char getSingleCharacter();
    char selectFromMainMenu();
    void startGame(bool gameDifficultyLevel);
    void clearMarks();
    void updateMarks();
    string createPieceSymbol(char type);
    void updateBoard();
    void displayTheBoard();
    string createSymbolOfFreePiece(int numberOfPiece);
    void updateFreePieces();
    void displayFreePieces();
    string getPieceSymbolFromUser();
    char changePieceSymbolToType(string symbol);
    int findPieceNumber(string symbol);
    int makeMove();

public:
    ConsoleUserInterface();
    //~ConsoleUserInterface();
    void displayMainMenu();
};

#endif // CONSOLEUSERINTERFACE_H
