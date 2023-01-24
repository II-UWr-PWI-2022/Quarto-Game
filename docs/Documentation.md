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
