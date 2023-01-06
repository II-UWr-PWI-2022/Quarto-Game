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
