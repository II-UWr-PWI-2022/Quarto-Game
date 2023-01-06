#include "Console_user_interface.h"

Console_user_interface::Console_user_interface()
{
    game = NULL;
}

/*
Asks user for input till get a single character, then returns it.
*/
char Console_user_interface::get_single_character()
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
char Console_user_interface::select_from_main_menu()
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
    choice = get_single_character();

    return choice;
}

/*
Starts the game in different mode depending on given argument.
Calls in loop the method responsible for making moves in game object.
Displays result of the game depending on the value
returned from last call of make move method.
After that calls for method displaying main menu.
*/
void Console_user_interface::start_game(bool game_difficulty_level)
{
    game = new Quarto_game(game_difficulty_level);
    clear_marks();
    int result;
    do
    {
        result = make_move();
    }
    while (result == 0);

    update_marks();
    display_the_board();

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

    display_main_menu();
}

/*
Sets marks as invisible for every field of displayed board
(see mark description in class declaration).
*/
void Console_user_interface::clear_marks()
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
void Console_user_interface::update_marks()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (game -> get_winning_pattern_field(i,j)) marks[i][j] = "----";
        }
    }
}

/*
Sets piece symbol using bit operations on type value given as an argument.
*/
string Console_user_interface::create_piece_symbol(char type)
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
void Console_user_interface::update_board()
{
    char piece_type;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            piece_type = game -> get_piece_type_from_board_field(i,j);
            if (piece_type == 0) board[i][j] = "    ";
            else board[i][j] = create_piece_symbol(piece_type);
        }
    }
}

/*
Displays the board.
*/
void Console_user_interface::display_the_board()
{
    update_board();
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
string Console_user_interface::create_symbol_of_free_piece(int number_of_piece)
{
    string symbol;
    if ((game -> is_piece_used(number_of_piece))) symbol = "----";
    else symbol = create_piece_symbol(game -> get_piece_type(number_of_piece));
    return symbol;
}

/*
Goes through the table of pieces in game object and sets dashes
instead of actual symbol in free pieces symbols table for all used pieces.
*/
void Console_user_interface::update_free_pieces()
{
    for (int i = 0; i < 16; i++)
    {
        free_pieces[i] = create_symbol_of_free_piece(i);
    }
}

/*
Display table of free pieces. The location of piece symbol in this table
is always the same. If piece is used, dashes are displayed instead of piece symbol.
*/
void Console_user_interface::display_free_pieces()
{
    update_free_pieces();
    cout << endl;
    cout << "                  FREE PIECES               " << endl;
    cout << "   -----------------------------------------" << endl;
    cout << internal << "      "<<free_pieces[0]<<"      "<<free_pieces[1]<<"      "<<free_pieces[2]<<"      "<<free_pieces[3]<<"    " << endl;
    cout << internal << "      "<<free_pieces[4]<<"      "<<free_pieces[5]<<"      "<<free_pieces[6]<<"      "<<free_pieces[7]<<"    " << endl;
    cout << internal << "      "<<free_pieces[8]<<"      "<<free_pieces[9]<<"      "<<free_pieces[10]<<"      "<<free_pieces[11]<<"    " << endl;
    cout << internal << "      "<<free_pieces[12]<<"      "<<free_pieces[13]<<"      "<<free_pieces[14]<<"      "<<free_pieces[15]<<"    " << endl;
}

/*
Asks user for piece symbol till the format is correct.
*/
string Console_user_interface::get_piece_symbol_from_user()
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
char Console_user_interface::change_piece_symbol_to_type(string symbol)
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
int Console_user_interface::find_piece_number(string symbol)
{
    char type = change_piece_symbol_to_type(symbol);
    int number = game -> find_piece_number(type);
    if (game -> is_piece_used(number)) number = 16;
    return number;
}

/*
Asks users for all arguments of make move method of game
object and checks the correctness of the entered data.
Then calls the method with arguments received from used.
*/
int Console_user_interface::make_move()
{
    display_the_board();
    display_free_pieces();

    // player making a move (0 is player A, 1 is player B)
    bool player = game -> get_player_active();

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
    int piece_number;
    char row;
    char column;

    // asking inactive player to chose a piece for active player
    cout << endl << "(Player " << player2 << "):" << endl;
    cout << "Chose the piece for Player " << player1 << ":" << endl;

    while (true)
    {
        symbol = get_piece_symbol_from_user();
        piece_number = find_piece_number(symbol);
        {
            if (piece_number < 16)
            {
                break;
            }
            else if (piece_number == 16)
            {
                cout << "This piece is already used. Chose another one:" << endl;
            }
            else if (piece_number == 100)
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
            row = get_single_character();
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
            column = get_single_character();
            if(column >= '1' && column <= '4')
            {
                break;
            }
            else
            {
                cout << "There is no such a column number. Use number from 1 to 4 according to the above game board notations. Type again:" << endl;
            }
        }
        if (game -> is_board_field_free(row-'A',column-'1'))
        {
            break;
        }
        else
        {
            cout << "There field is not free. Chose another one:." << endl;
        }
    }

    // actual move in Quarto game object
    int result = (game -> make_move(row-'A',column-'1',piece_number));

    return result;
}

/*
Displays main menu. Depending on user's choice start game in chosen
mode or close the program.
*/
void Console_user_interface::display_main_menu()
{
    char choice;

    while (true)
    {
        choice = select_from_main_menu();

        switch (choice)
        {
        case '1':
            start_game(0);
            break;
        case '2':
            start_game(1);
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
