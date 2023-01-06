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

