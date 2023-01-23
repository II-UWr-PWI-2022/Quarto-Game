#include "Console_user_interface.h"

Console_user_interface::Console_user_interface() : db_manager("../db/users.xml")
{
    human_player_1.connect_with_database(db_manager);
    human_player_2.connect_with_database(db_manager);

    game = NULL;
    bot_random_1 = NULL;
    bot_random_2 = NULL;
    bot_minmax_1 = NULL;
    bot_minmax_2 = NULL;
    bot_superior_1 = NULL;
    bot_superior_2 = NULL;
}

/*
Asks user for input till get a single character, then returns it.
*/
char Console_user_interface::get_single_character()
{
    string input = "";
    char character = {0};

    while(true)
    {
        getline(cin, input);

        if(input.length() == 1)
        {
            character = input[0];

		    break;
        }

        cout << "This is not a single character. Type again:" << "\n";
    }

    return character;
}

/*
Displays main menu and ask for choice, then returns the choice.
*/
char Console_user_interface::select_from_main_menu()
{
    char choice;

    clear_console();

    cout << " >>> QUARTO GAME <<<" << "\n";
    cout << "---------------------------" << "\n";
    cout << "1. Play EASY version" << "\n";
    cout << "2. Play HARD version" << "\n";
    cout << "3. Exit" << "\n";
    cout << "---------------------------" << "\n";
    cout << "Your choice: ";

    choice = get_single_character();

    return choice;
}

/*
Displays player menu and ask for choice, then returns the choice.
*/
char Console_user_interface::select_from_player_menu(char player)
{
    char choice;

    clear_console();

    cout << " >>> QUARTO GAME <<<" << "\n";
    cout << "---------------------------" << "\n";
    cout << "Choose who will play as a player " << player << ":" << "\n";
    cout << "1. Human" << "\n";
    cout << "2. Bot 1" << "\n";
    cout << "3. Bot 2" << "\n";
    cout << "4. Bot 3" << "\n";
    cout << "5. Exit" << "\n";
    cout << "---------------------------" << "\n";
    cout << "Your choice: ";

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
    bot_random_1 = new Bot_Random();
    bot_random_2 = new Bot_Random();
	bot_minmax_1 = new Bot_Minmax();
	bot_minmax_2 = new Bot_Minmax();
	bot_superior_1 = new Bot_Superior();
	bot_superior_2 = new Bot_Superior();
    srand(time(NULL));
    clear_marks();

    int result;

    do
    {
        result = make_move();
    }
    while(result == 0);

    update_marks();
    display_the_board();

    cout << "   -----------------------------------------" << "\n";

    if(result == 1)
    {
        cout << "             Player A wins!              " << "\n";
    }

    else if(result == 2)
    {
        cout << "             Player B wins!              " << "\n";
    }

    else if(result == 3)
    {
        cout << "                  Draw!                  " << "\n";
    }

    cout << "   -----------------------------------------" << "\n" << "\n";

    delete game;
    delete bot_random_1;
    delete bot_random_2;
    delete bot_minmax_1;
    delete bot_minmax_2;
    delete bot_superior_1;
    delete bot_superior_2;
    game = NULL;
    bot_random_1 = NULL;
    bot_random_2 = NULL;
    bot_minmax_1 = NULL;
    bot_minmax_2 = NULL;
    bot_superior_1 = NULL;
    bot_superior_2 = NULL;

    cout << "Press enter to go back to main menu..." << "\n";

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
    for(int i = 0; i < MAX_N; i++)
    {
        for(int j = 0; j < MAX_N; j++)
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
    for(int i = 0; i < MAX_N; i++)
    {
        for(int j = 0; j < MAX_N; j++)
        {
            if(game->get_winning_pattern_field(i,j)) marks[i][j] = "----";
        }
    }
}

/*
Sets piece symbol using bit operations on type value given as an argument.
*/
string Console_user_interface::create_piece_symbol(int type)
{
    string symbol = "";

    if((type >> 0) & 1)
    {
        symbol += 'D';
    }

    else
    {
        symbol += 'L';
    }

    if((type >> 1) & 1)
    {
        symbol += 'R';
    }

    else
    {
        symbol += 'S';
    }

    if((type >> 2) & 1)
    {
        symbol += 'T';
    }

    else
    {
        symbol += 'S';
    }

    if((type >> 3) & 1)
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

    for(int i = 0; i < MAX_N; i++)
    {
        for(int j = 0; j < MAX_N; j++)
        {
            piece_type = game->get_piece_type_from_board_field(i,j);

            if(piece_type == 16)
			{
				board[i][j] = "    ";
			}

            else
			{
				board[i][j] = create_piece_symbol(piece_type);
        	}
    	}
	}
}

/*
Displays the board.
*/
void Console_user_interface::display_the_board()
{
    update_board();

    clear_console();

    cout << "              >>> QUARTO GAME <<<           " << "\n\n";
    cout << internal << "   |    1    |    2    |    3    |    4    |" << "\n";
    cout << "--------------------------------------------" << "\n";
    cout << internal << "   |  "<<marks[0][0]<<"   |  "<<marks[0][1]<<"   |  "<<marks[0][2]<<"   |  "<<marks[0][3]<<"   |" << "\n";
    cout << internal << " A |  "<<board[0][0]<<"   |  "<<board[0][1]<<"   |  "<<board[0][2]<<"   |  "<<board[0][3]<<"   |" << "\n";
    cout << internal << "   |  "<<marks[0][0]<<"   |  "<<marks[0][1]<<"   |  "<<marks[0][2]<<"   |  "<<marks[0][3]<<"   |" << "\n";
    cout << "--------------------------------------------" << "\n";
    cout << internal << "   |  "<<marks[1][0]<<"   |  "<<marks[1][1]<<"   |  "<<marks[1][2]<<"   |  "<<marks[1][3]<<"   |" << "\n";
    cout << internal << " B |  "<<board[1][0]<<"   |  "<<board[1][1]<<"   |  "<<board[1][2]<<"   |  "<<board[1][3]<<"   |" << "\n";
    cout << internal << "   |  "<<marks[1][0]<<"   |  "<<marks[1][1]<<"   |  "<<marks[1][2]<<"   |  "<<marks[1][3]<<"   |" << "\n";
    cout << "--------------------------------------------" << "\n";
    cout << internal << "   |  "<<marks[2][0]<<"   |  "<<marks[2][1]<<"   |  "<<marks[2][2]<<"   |  "<<marks[2][3]<<"   |" << "\n";
    cout << internal << " C |  "<<board[2][0]<<"   |  "<<board[2][1]<<"   |  "<<board[2][2]<<"   |  "<<board[2][3]<<"   |" << "\n";
    cout << internal << "   |  "<<marks[2][0]<<"   |  "<<marks[2][1]<<"   |  "<<marks[2][2]<<"   |  "<<marks[2][3]<<"   |" << "\n";
    cout << "--------------------------------------------" << "\n";
    cout << internal << "   |  "<<marks[3][0]<<"   |  "<<marks[3][1]<<"   |  "<<marks[3][2]<<"   |  "<<marks[3][3]<<"   |" << "\n";
    cout << internal << " D |  "<<board[3][0]<<"   |  "<<board[3][1]<<"   |  "<<board[3][2]<<"   |  "<<board[3][3]<<"   |" << "\n";
    cout << internal << "   |  "<<marks[3][0]<<"   |  "<<marks[3][1]<<"   |  "<<marks[3][2]<<"   |  "<<marks[3][3]<<"   |" << "\n";
    cout << "--------------------------------------------" << "\n";
}

/*
Returns actual piece symbol for piece from pieces table in game object
for free pieces or dashes for used pieces.
*/
string Console_user_interface::create_symbol_of_free_piece(int number_of_piece)
{
    string symbol;

    if((game->is_piece_used(number_of_piece)))
	{
		symbol = "----";
	}

	else
	{
		symbol = create_piece_symbol(game->get_piece_type(number_of_piece));
	}

	return symbol;
}

/*
Goes through the table of pieces in game object and sets dashes
instead of actual symbol in free pieces symbols table for all used pieces.
*/
void Console_user_interface::update_free_pieces()
{
    for(int i = 0; i < MAX_NUMBER_OF_PIECES; i++)
    {
        free_pieces[i] = create_symbol_of_free_piece(i);
    }
}

/*
Display table of free pieces. The location of piece symbol in this table
is always the same. ifpiece is used, dashes are displayed instead of piece symbol.
*/
void Console_user_interface::display_free_pieces()
{
    update_free_pieces();
    cout << "\n";
    cout << "                  FREE PIECES               " << "\n";
    cout << "   -----------------------------------------" << "\n";
    cout << internal << "      "<<free_pieces[0]<<"      "<<free_pieces[1]<<"      "<<free_pieces[2]<<"      "<<free_pieces[3]<<"    " << "\n";
    cout << internal << "      "<<free_pieces[4]<<"      "<<free_pieces[5]<<"      "<<free_pieces[6]<<"      "<<free_pieces[7]<<"    " << "\n";
    cout << internal << "      "<<free_pieces[8]<<"      "<<free_pieces[9]<<"      "<<free_pieces[10]<<"      "<<free_pieces[11]<<"    " << "\n";
    cout << internal << "      "<<free_pieces[12]<<"      "<<free_pieces[13]<<"      "<<free_pieces[14]<<"      "<<free_pieces[15]<<"    " << "\n";
}

/*
Asks user for piece symbol till the format is correct.
*/
string Console_user_interface::get_piece_symbol_from_user()
{
    string input = "";

    while(true)
    {
        getline(cin, input);

        if(input.length() == MAX_N
            && (input[0] == 'D' || input[0] == 'L')
            && (input[1] == 'R' || input[1] == 'S')
            && (input[2] == 'T' || input[2] == 'S')
            && (input[3] == 'S' || input[3] == 'H'))
        {
            break;
        }

        cout << "There is no such a symbol. Use the four-letter symbol according to the above table of free pieces. Type again:" << "\n";
    }
    return input;
}

/*
Calculates piece type using bit operations for
piece symbol received from user.
*/
int Console_user_interface::change_piece_symbol_to_type(string symbol)
{
    int type = 0;

    if(symbol[0] == 'D') type |= (1 << 0);
    if(symbol[1] == 'R') type |= (1 << 1);
    if(symbol[2] == 'T') type |= (1 << 2);
    if(symbol[3] == 'S') type |= (1 << 3);

    return type;
}

/*
Returns index number in pieces table of game object
corresponding to piece symbol.
*/
int Console_user_interface::find_piece_number(string symbol)
{
    int type = change_piece_symbol_to_type(symbol);

    int number = game->find_piece_number(type);

    if(game->is_piece_used(number)) number = MAX_NUMBER_OF_PIECES;

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

    // is_player_2 (0 is player A, 1 is player B)
    bool is_player_2 = game->get_player_active();

    string player_1;
    string player_2;

    if(is_player_2)
    {
        player_1 = "B";
        player_2 = "A";
    }
    else
    {
        player_1 = "A";
        player_2 = "B";
    }

    string symbol;
    int piece_number;
    char row;
    char column;

    // asking inactive player to chose a piece for active player
    cout << "\n" << "(Player " << player_2 << "):" << "\n";
    cout << "Chose the piece for Player " << player_1 << ":" << "\n";

	bool is_human = false;

	if(!is_player_2)
	{
		if(index_player_B == HUMAN)
		{
			is_human = true;
		}
	}

	else
	{
		if(index_player_A == HUMAN)
		{
			is_human = true;
		}
	}

	if(is_human)
	{
		while(true)
		{
			symbol = get_piece_symbol_from_user();
			piece_number = find_piece_number(symbol);

			if(piece_number < MAX_NUMBER_OF_PIECES)
			{
				break;
			}

			else if(piece_number == MAX_NUMBER_OF_PIECES)
			{
				cout << "This piece is already used. Chose another one:" << "\n";
			}

			else if(piece_number == 100)
			{
				cout << "This piece does not exist. Chose another one:" << "\n";
			}
		}
	}

	else
	{
		wait(500);
		if(!is_player_2)
		{
			switch(index_player_B)
			{
			case BOT_1:
				piece_number = bot_random_2->get_chosen_piece_type();

				break;
			case BOT_2:
				piece_number = bot_minmax_2->get_chosen_piece_type();

				break;
			case BOT_3:
				piece_number = bot_superior_2->get_chosen_piece_type();

                break;
			default:
				break;
			}
		}

		else
		{
			switch(index_player_A)
			{
			case BOT_1:
				piece_number = bot_random_1->get_chosen_piece_type();

				break;
			case BOT_2:
				piece_number = bot_minmax_1->get_chosen_piece_type();

				break;
			case BOT_3:
				piece_number = bot_superior_1->get_chosen_piece_type();

                break;
			default:
				break;
			}
		}
		symbol = create_piece_symbol(game->get_piece_type(piece_number));
		cout << symbol << "\n";
	}

	game -> set_piece_as_used(piece_number);

    // asking active player to chose a field on board for his piece
    cout << "\n" << "(Player " << player_1 << "):" << "\n";
    cout << "Chose the field for piece " << symbol << ":" << "\n";

	is_human = false;

	if(is_player_2)
	{
		if(index_player_B == HUMAN)
		{
			is_human = true;
		}
	}

	else
	{
		if(index_player_A == HUMAN)
		{
			is_human = true;
		}
	}

	if(is_human)
	{
		while(true)
		{
			cout << "Type the row symbol:" << "\n";

			while(true)
			{
				row = get_single_character();

				if(row >= 'A' && row <= 'D')
				{
					break;
				}

				else
				{
					cout << "There is no such a row symbol. Use letter from A to D according to the above game board notations. Type again:" << "\n";
				}
			}

			cout << "Type the column number:" << "\n";

			while(true)
			{
				column = get_single_character();

				if(column >= '1' && column <= '4')
				{
					break;
				}

				else
				{
					cout << "There is no such a column number. Use number from 1 to 4 according to the above game board notations. Type again:" << "\n";
				}
			}

			if(game->is_board_field_free(row-'A',column-'1'))
			{
				break;
			}

			else
			{
				cout << "There field is not free. Choose another one:" << "\n";
			}
		}
	}

	else
	{
		wait(1000);
		pair <int, int> field;

		if(is_player_2)
		{
			switch(index_player_B)
			{
			case BOT_1:
				bot_random_2->analyze_position(game, piece_number);
				field = bot_random_2->get_chosen_board_field();

				break;
			case BOT_2:
				bot_minmax_2->analyze_position(game, piece_number);
				field = bot_minmax_2->get_chosen_board_field();

				break;
			case BOT_3:
				bot_superior_2->analyze_position(game, piece_number);
				field = bot_superior_2->get_chosen_board_field();
				break;

			default:
				break;
			}
		}

		else
		{
			switch(index_player_A)
			{
			case BOT_1:
				bot_random_1->analyze_position(game, piece_number);
				field = bot_random_1->get_chosen_board_field();

				break;
			case BOT_2:
				bot_minmax_1->analyze_position(game, piece_number);
				field = bot_minmax_1->get_chosen_board_field();

				break;
			case BOT_3:
				bot_superior_1->analyze_position(game, piece_number);
				field = bot_superior_1->get_chosen_board_field();

				break;

			default:
				break;
			}
		}

		row = field.first + 'A';
		column = field.second + '1';
	}

    // actual move in Quarto game object
    int result = (game->make_move(row-'A',column-'1',piece_number));

    return result;
}

/*
Displays main menu. Depending on user's choice start game in chosen
mode or close the program.
*/
void Console_user_interface::display_main_menu()
{
    char choice;

    while(true)
    {
        choice = select_from_main_menu();

        switch (choice)
        {
        case '1':
			index_player_A = display_player_menu('A');
			index_player_B = display_player_menu('B');

            start_game(0);

            break;
        case '2':
			index_player_A = display_player_menu('A');
			index_player_B = display_player_menu('B');

            start_game(1);

            break;
        case '3':
            exit(0);

            break;
        default:
            cout << "\n" << "There is no such option in the menu." << "\n\n";
            cout << "Press enter to go back to try again..." << "\n";

            string choice = "";
            getline(cin, choice);

            break;
        }
    }
}

/*
Displays player menu. Depending on the user's choice, it will start the game against a human or bot with a given ID in the chosen game mode or close the program
TODO: poprawic
*/
int Console_user_interface::display_player_menu(char player)
{
    char choice;

    while(true)
    {
        choice = select_from_player_menu(player);

		if('1' <= choice && choice <= '5')
		{
			if(choice == '5')
			{
				exit(0);
			}

			return choice - '1';
		}

	   	else
		{
            cout << "\n" << "There is no such option in the menu." << "\n\n";
            cout << "Press enter to go back to try again..." << "\n";

            string choice = "";
            getline(cin, choice);
        }
    }
}
