#include <iostream>
#include "QuartoGame.h"

using namespace std;

int main()
{
    QuartoGame *game;
    game = new QuartoGame(1);
    delete game;
    return 0;
}
