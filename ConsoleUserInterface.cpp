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
            game = new QuartoGame(1);
            makeMove();
            break;
        case '2':

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
