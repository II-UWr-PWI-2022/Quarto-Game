# Documentation
## game_interface.cpp
### Classes
#### fieldOnBoard
Class that was made for fields which are on board. It contain:

```bool isOccupied``` - bolean variable that keeps information is something on this field.

```int XpositionOfLeftUpCorner```, ```int YpositionOfLeftUpCorner```, ```int XpositionOfRightDownCorner```, ```int YpositionOfRightDownCorner``` - int variables 
that contain informationabout position of field in window.

```string whatTypeOfPieceisOn``` - string variable that contain four-letter code of piece that is on this fields, if nothing is on its empty (""). 

```Sprite sprt``` - Sprite type (SFML) variable that contain sprite of piece that is on this field.

#### fieldNextToBoard
Class that was made for fields which are next to board. It contain:

```bool isPieceStillOn``` - bolean type variable that keeps information is piece still on this field.

```int XpositionOfLeftUpCorner```, ```int YpositionOfLeftUpCorner```, ```int XpositionOfRightDownCorner```, ```int YpositionOfRightDownCorner``` - int variables 
that contain informationabout position of field in window.

```string whatTypeOfPieceisOn``` - string variable that contain four-letter code of piece that is on this fields, if nothing is on its empty ("").

#### piece
Class that was made for pieces. It contain:

```int Xposition```, ```int Yposition``` - int type variables that contain information about X and Y position of piece in window.

```string code``` - string type variable that contain four letter code of piece.

```string OnWhichFieldIsIt``` - string type variable that contain name of field which this piece is on.

```Sprite sprt``` - Sprite type (SFML) that contain sprite of piece.

```bool isItPlaced``` - bolean type variable that contain information is piece placed on board.

```Texture tex``` - Texture type (SFML) that contain texture of piece.

## menu.cpp
### Classes
#### button
Class that was made for buttons. It contain:

```bool isPressed``` - bolean type variable that contain information is button pressed.

```int Xposition```, ```int Yposition``` - int type variable that contain information about X and Y position of button in window.

```bool isMouseOn``` - bolean type variable that contain information is cursor of mouse on button. 

```Text text``` - Text type (SFML) variable that contain information about textbox of button.

## Bot_minmax.cpp
### Classes
#### Bot_Minmax
A bot based on min-max algorithm. It contains:

```int random_int(int L, int R)``` - returns random integer from range [L, R].

```bool is_pattern_winning(int p1, int p2, int p3, int p4)``` - checks if four pieces given as arguments have at least one common characteristic.

```bool is_board_winning()``` - depending on game difficulty checks if there is a line or square of fields that share at least one common characteristics.

```int evaluate(int piece)``` - calculates the value of current state of board and the given piece.

```void set_choice(int row, int column int opponent_piece)``` - sets move as best, updates the chosen move.

```int minmax(int depth, int piece, int max_depth)``` - Analizes potential arrangement of pieces on board using recursive minmax algorithm and depending on results chooses the best move. Maximum depth of algorithm is sets to 2.

```void last_move()``` - Finds the last empty field for the last piece.

```int get_chosen_piece_type()``` - Returns a piece that bot wants to give to the opponent.

```pair <int, int> get_chosen_board_field()``` - Returns a field where bot wants to place given piece.

```void analyze_position(Quarto_game* game, int piece)``` - Reads board and game difficulty, and launches minmax function to find the best move.

## Bot_superior.cpp
### Classes
#### Bot_Superior
A bot based on min-max algorithm, searching the moves tree deeper than Bot_minmax, and evauating bords with different function. It contains:

```int random_int(int L, int R)``` - returns random integer from range [L, R].

```bool is_pattern_winning(int p1, int p2, int p3, int p4)``` - checks if four pieces given as arguments have at least one common characteristic.

```bool is_board_winning()``` - depending on game difficulty checks if there is a line or square of fields that share at least one common characteristics.

```bool is_triple(int given_piece, vector<int> pattern)``` - Checks if putting given piece on one of the empty fields from vector "pattern" forms a triple with at least one common characteristic.

```int evaluate(int piece)``` - Counts value of the board with a piece that will be put on it, based on how many ways of putting that piece form a tripple - the less such moves the better.

```void set_choice(int row, int column int opponent_piece)``` - sets move as best, updates the chosen move.

```int minmax(int depth, int piece, int max_depth)``` - Analizes potential arrangement of pieces on board using recursive minmax algorithm and depending on results chooses the best move Maximum depth of algorithm depends on how many pieces are left

```void last_move()``` - Finds the last empty field for the last piece.

```int get_chosen_piece_type()``` - Returns a piece that bot wants to give to the opponent.

```pair <int, int> get_chosen_board_field()``` - Returns a field where bot wants to place given piece.

```void analyze_position(Quarto_game* game, int piece)``` - Reads board and game difficulty, and launches minmax function to find the best move.

## Bot_random.cpp
### Classes
#### Bot_random
A bot that makes random moves, with equal probability of choosing each possible move. It contains:

```int random_int(int L, int R)``` - returns random integer from range [L, R].

```int get_chosen_piece_type()``` - Returns a piece that bot wants to give to the opponent.

```pair <int, int> get_chosen_board_field()``` - Returns a field where bot wants to place given piece.

```void analyze_position(Quarto_game* game, int piece)``` - Reads board and game difficulty and chooses random move to make.

## Quarto_game
### class Quarto_game 
Main game class
#### private:
```void put_piece_on_board(int row, int column, int piece_number)``` - Search for type of piece defined by its number in table of pieces in Quarto game object. Then this value is assigned to the field in the board specified by row and column number.

```void change_player()``` - Sets the value of active player to the opposite.

```bool is_game_finished_in_easy_version(int row, int column)``` - Checks, in easy mode, by using bit operations if after last move are there four pieces on appropriate fields, which have the same value of at least one characteristic. If yes, it sets the winning pattern and returns true, it not - it returns false.

```bool is_game_finished_in_hard_version(int row, int column)``` - Puts piece on board, then checks if there are any winning pattern and game is finished, if yes it returns different value depending on the player making the last move, if not it checks how many pieces have been used and if there is draw, if not it changes the active user and returns 0.

#### public:
```Quarto_game(bool game_difficulty_level)``` - Constructor. It takes as an argument a bool variable. If the value of argument is true, the game is played in hard mode, if it is false - in easy mode.

```int make_move(int row, int column, int piece_number)``` - Puts piece on board, then checks if there are any winning pattern and game is finished, if yes it returns different value depending on the player making the last move, if not it checks how many pieces have been used and if there is draw, if not it changes the active user and returns 0.

```bool is_piece_used(int number_of_piece)``` - Checks if particular piece from table of pieces in Quarto game object has been used.

```bool is_board_field_free(int row, int column)``` - Checks if particular field on board is free.

```bool get_winning_pattern_field(int row, int column)``` - Checks if on particular field of board is located one of pieces forming a winning pattern.

```int get_piece_type(int number_of_piece)``` - Returns the type of piece defined by its index number in table of pieces in Quarto game object.

```bool get_player_active()``` - Returns true when player B is active and false when it is player A. Active player is the one making move.

```int get_piece_type_from_board_field(int row, int column)``` - Returns the value of piece which is located on the board field specified by row and column number.

```int find_piece_number(int type_of_piece)``` - Returns the number of index in table of pieces in Quarto game object for piece defined by its type.

```bool get_game_difficulty_level()``` - Returns bool which contain information about game difficulty.

```void set_piece_as_used(int piece_number)``` - Marks piece as used.

## DB_menager
### class DB_Menager
#### private:
```void add_player(const Player &player)``` -  adds a player to the database.

```void update_player(const Player &player)``` - updates the player's state in the database with the real state

#### public:
```DB_manager(const std::string access_path)``` - The constructor takes the path to the xml file as an argument and loads the database from it.

```~DB_manager()``` - The destructor saves the database to an xml file.

```pair<bool, Player> search_nickname(std::string _nick_name)``` -  Searches for a player in the database by given nickname. Returns Pair<True/False, Player> Depending on the success of the search operation.

```vector<Player> generate_ranking(Sort_by key, Order order_type)``` - It generates a ranking of players by sorting in terms of the indicated feature and in the designated order.
