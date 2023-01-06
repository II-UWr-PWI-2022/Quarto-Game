#include "ConsoleUserInterface.h"

ConsoleUserInterface::ConsoleUserInterface()
{
    game = NULL;
}

/*
ConsoleUserInterface::~ConsoleUserInterface()
{
    cout << "console destructor" << endl;
}
*/

/*
Asks user for input till get a single character, then returns it.
*/
char ConsoleUserInterface::getSingleCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Type again:" << endl;
    }
    return character;
}

/*
Displays main menu and ask for choice, then returns the choice.
*/
char ConsoleUserInterface::selectFromMainMenu()
{
    char choice;

    if (system("cls")) system("clear");
    cout << " >>> QUARTO GAME <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Play EASY version" << endl;
    cout << "2. Play HARD version" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "You choice: ";
    choice = getSingleCharacter();

    return choice;
}

/*
Starts the game in different mode depending on given argument.
Calls in loop the method responsible for making moves in game object.
Displays result of the game depending on the value
returned from last call of make move method.
After that calls for method displaying main menu.
*/
void ConsoleUserInterface::startGame(bool gameDifficultyLevel)
{
    game = new QuartoGame(gameDifficultyLevel);
    clearMarks();
    int result;
    do
    {
        result = makeMove();
    }
    while (result == 0);

    updateMarks();
    displayTheBoard();

    cout << "   -----------------------------------------" << endl;

    if (result == 1)
    {
        cout << "             Player A wins!              " << endl;
    }
    else if (result == 2)
    {
        cout << "             Player B wins!              " << endl;
    }
    else if (result == 3)
    {
        cout << "                  Draw!                  " << endl;
    }

    cout << "   -----------------------------------------" << endl << endl;

    delete game;
    game = NULL;

    cout << "Press enter to go back to main menu..." << endl;

    string choice = "";
    getline(cin, choice);

    displayMainMenu();
}

/*
Sets marks as invisible for every field of displayed board
(see mark description in class declaration).
*/
void ConsoleUserInterface::clearMarks()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            marks[i][j] = "    ";
        }
    }
}

/*
Sets dashes instead spaces for every field of board corresponding to winner
pattern - makes marks visible for these fields.
*/
void ConsoleUserInterface::updateMarks()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game -> getWinningPatternField(i,j)) marks[i][j] = "----";
        }
    }
}

/*
Sets piece symbol using bit operations on type value given as an argument.
*/
string ConsoleUserInterface::createPieceSymbol(char type)
{
    string symbol = "";

    if ((type >> 0)&1)
    {
        symbol += 'D';
    }
    else
    {
        symbol += 'L';
    }

    if ((type >> 2)&1)
    {
        symbol += 'R';
    }
    else
    {
        symbol += 'S';
    }

    if ((type >> 4)&1)
    {
        symbol += 'T';
    }
    else
    {
        symbol += 'S';
    }

    if ((type >> 6)&1)
    {
        symbol += 'S';
    }
    else
    {
        symbol += 'H';
    }

    return symbol;
}

/*
Goes through the board of game object and sets piece types in
board of console interface object.
*/
void ConsoleUserInterface::updateBoard()
{
    char pieceType;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            pieceType = game -> getPieceTypeFromBoardField(i,j);
            if (pieceType == 0) board[i][j] = "    ";
            else board[i][j] = createPieceSymbol(pieceType);
        }
    }
}

/*
Displays the board.
*/
void ConsoleUserInterface::displayTheBoard()
{
    updateBoard();
    if (system("cls")) system("clear");
    cout << "              >>> QUARTO GAME <<<           " << endl << endl;
    cout << internal << "   |    1    |    2    |    3    |    4    |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << internal << "   |  "<<marks[0][0]<<"   |  "<<marks[0][1]<<"   |  "<<marks[0][2]<<"   |  "<<marks[0][3]<<"   |" << endl;
    cout << internal << " A |  "<<board[0][0]<<"   |  "<<board[0][1]<<"   |  "<<board[0][2]<<"   |  "<<board[0][3]<<"   |" << endl;
    cout << internal << "   |  "<<marks[0][0]<<"   |  "<<marks[0][1]<<"   |  "<<marks[0][2]<<"   |  "<<marks[0][3]<<"   |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << internal << "   |  "<<marks[1][0]<<"   |  "<<marks[1][1]<<"   |  "<<marks[1][2]<<"   |  "<<marks[1][3]<<"   |" << endl;
    cout << internal << " B |  "<<board[1][0]<<"   |  "<<board[1][1]<<"   |  "<<board[1][2]<<"   |  "<<board[1][3]<<"   |" << endl;
    cout << internal << "   |  "<<marks[1][0]<<"   |  "<<marks[1][1]<<"   |  "<<marks[1][2]<<"   |  "<<marks[1][3]<<"   |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << internal << "   |  "<<marks[2][0]<<"   |  "<<marks[2][1]<<"   |  "<<marks[2][2]<<"   |  "<<marks[2][3]<<"   |" << endl;
    cout << internal << " C |  "<<board[2][0]<<"   |  "<<board[2][1]<<"   |  "<<board[2][2]<<"   |  "<<board[2][3]<<"   |" << endl;
    cout << internal << "   |  "<<marks[2][0]<<"   |  "<<marks[2][1]<<"   |  "<<marks[2][2]<<"   |  "<<marks[2][3]<<"   |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << internal << "   |  "<<marks[3][0]<<"   |  "<<marks[3][1]<<"   |  "<<marks[3][2]<<"   |  "<<marks[3][3]<<"   |" << endl;
    cout << internal << " D |  "<<board[3][0]<<"   |  "<<board[3][1]<<"   |  "<<board[3][2]<<"   |  "<<board[3][3]<<"   |" << endl;
    cout << internal << "   |  "<<marks[3][0]<<"   |  "<<marks[3][1]<<"   |  "<<marks[3][2]<<"   |  "<<marks[3][3]<<"   |" << endl;
    cout << "--------------------------------------------" << endl;
}

/*
Returns actual piece symbol for piece from pieces table in game object
for free pieces or dashes for used pieces.
*/
string ConsoleUserInterface::createSymbolOfFreePiece(int numberOfPiece)
{
    string symbol;
    if ((game -> isPieceUsed(numberOfPiece))) symbol = "----";
    else symbol = createPieceSymbol(game -> getPieceType(numberOfPiece));
    return symbol;
}

/*
Goes through the table of pieces in game object and sets dashes
instead of actual symbol in free pieces symbols table for all used pieces.
*/
void ConsoleUserInterface::updateFreePieces()
{
    for (int i = 0; i < 16; i++)
    {
        freePieces[i] = createSymbolOfFreePiece(i);
    }
}

/*
Display table of free pieces. The location of piece symbol in this table
is always the same. If piece is used, dashes are displayed instead of piece symbol.
*/
void ConsoleUserInterface::displayFreePieces()
{
    updateFreePieces();
    cout << endl;
    cout << "                  FREE PIECES               " << endl;
    cout << "   -----------------------------------------" << endl;
    cout << internal << "      "<<freePieces[0]<<"      "<<freePieces[1]<<"      "<<freePieces[2]<<"      "<<freePieces[3]<<"    " << endl;
    cout << internal << "      "<<freePieces[4]<<"      "<<freePieces[5]<<"      "<<freePieces[6]<<"      "<<freePieces[7]<<"    " << endl;
    cout << internal << "      "<<freePieces[8]<<"      "<<freePieces[9]<<"      "<<freePieces[10]<<"      "<<freePieces[11]<<"    " << endl;
    cout << internal << "      "<<freePieces[12]<<"      "<<freePieces[13]<<"      "<<freePieces[14]<<"      "<<freePieces[15]<<"    " << endl;
}

/*
Asks user for piece symbol till the format is correct.
*/
string ConsoleUserInterface::getPieceSymbolFromUser()
{
    string input = "";

    while (true)
    {
        getline(cin, input);

        if (input.length() == 4
                && (input[0] == 'D' || input[0] == 'L')
                && (input[1] == 'R' || input[1] == 'S')
                && (input[2] == 'T' || input[2] == 'S')
                && (input[3] == 'S' || input[3] == 'H'))
        {
            break;
        }
        cout << "There is no such a symbol. Use the four-letter symbol according to the above table of free pieces. Type again:" << endl;
    }
    return input;
}

/*
Calculates piece type using bit operations for
piece symbol received from user.
*/
char ConsoleUserInterface::changePieceSymbolToType(string symbol)
{
    char type = 0;

    if (symbol[0] == 'D') type = type | 1 << 0;
    if (symbol[0] == 'L') type = type | 1 << 1;
    if (symbol[1] == 'R') type = type | 1 << 2;
    if (symbol[1] == 'S') type = type | 1 << 3;
    if (symbol[2] == 'T') type = type | 1 << 4;
    if (symbol[2] == 'S') type = type | 1 << 5;
    if (symbol[3] == 'S') type = type | 1 << 6;
    if (symbol[3] == 'H') type = type | 1 << 7;

    return type;
}

/*
Returns index number in pieces table of game object
corresponding to piece symbol.
*/
int ConsoleUserInterface::findPieceNumber(string symbol)
{
    char type = changePieceSymbolToType(symbol);
    int number = game -> findPieceNumber(type);
    if (game -> isPieceUsed(number)) number = 16;
    return number;
}

/*
Asks users for all arguments of make move method of game
object and checks the correctness of the entered data.
Then calls the method with arguments received from used.
*/
int ConsoleUserInterface::makeMove()
{
    displayTheBoard();
    displayFreePieces();

    // player making a move (0 is player A, 1 is player B)
    bool player = game -> getPlayerActive();

    string player1;
    string player2;

    if (player)
    {
        player1 = "B";
        player2 = "A";
    }
    else
    {
        player1 = "A";
        player2 = "B";
    }

    string symbol;
    int pieceNumber;
    char row;
    char column;

    // asking inactive player to chose a piece for active player
    cout << endl << "(Player " << player2 << "):" << endl;
    cout << "Chose the piece for Player " << player1 << ":" << endl;

    while (true)
    {
        symbol = getPieceSymbolFromUser();
        pieceNumber = findPieceNumber(symbol);
        {
            if (pieceNumber < 16)
            {
                break;
            }
            else if (pieceNumber == 16)
            {
                cout << "This piece is already used. Chose another one:" << endl;
            }
            else if (pieceNumber == 100)
            {
                cout << "This piece does not exist. Chose another one:" << endl;
            }
        }
    }

    // asking active player to chose a field on board for his piece
    cout << endl << "(Player " << player1 << "):" << endl;
    cout << "Chose the field for piece " << symbol << ":" << endl;

    while (true)
    {
        cout << "Type the row symbol:" << endl;
        while (true)
        {
            row = getSingleCharacter();
            if(row >= 'A' && row <= 'D')
            {
                break;
            }
            else
            {
                cout << "There is no such a row symbol. Use letter from A to D according to the above game board notations. Type again:" << endl;
            }
        }
        cout << "Type the column number:" << endl;
        while (true)
        {
            column = getSingleCharacter();
            if(column >= '1' && column <= '4')
            {
                break;
            }
            else
            {
                cout << "There is no such a column number. Use number from 1 to 4 according to the above game board notations. Type again:" << endl;
            }
        }
        if (game -> isBoardFieldFree(row-'A',column-'1'))
        {
            break;
        }
        else
        {
            cout << "There field is not free. Chose another one:." << endl;
        }
    }

    // actual move in QuartoGame object
    int result = (game -> makeMove(row-'A',column-'1',pieceNumber));

    return result;
}

/*
Displays main menu. Depending on user's choice start game in chosen
mode or close the program.
*/
void ConsoleUserInterface::displayMainMenu()
{
    char choice;

    while (true)
    {
        choice = selectFromMainMenu();

        switch (choice)
        {
        case '1':
            startGame(0);
            break;
        case '2':
            startGame(1);
            break;
        case '3':
            exit(0);
            break;
        default:
            cout << endl << "There is no such option in the menu." << endl << endl;
            cout << "Press enter to go back to try again..." << endl;

            string choice = "";
            getline(cin, choice);
            break;
        }
    }
}
