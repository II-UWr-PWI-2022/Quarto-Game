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
```random_int``` - returns random integer
```is_pattern_winning``` - checks if four pieces given as arguments have at least one common characteristic
```is_board_winning``` - depending on game difficulty checks if there is a line or square of fields that share at least one common characteristics
```evaluate``` calculates the value of current state of board and the given piece
