# Board.h
This contains the declaration of Board class.This class is designed to handle all the tasks in the game that require use of the 
game Board.It also declares some game constants such as O_VAL, X_VAL ,BLANK, TIE_GAME.
# Board.cpp
It implements the member functions of the Board class.The important function is the checkWin() function. It checks if player with symbol 
'o' or 'x' win or if the game is a tie.

void clearBoard() -> To clear the board i.e fill the cells with a symbol or number associated with constant BLANK.

int getVal(int x,int y); -> To retrieve the symbol stored in the cell with coordinates (x,y).

void setVal(int x,int y,int player);-> To insert the symbol in the cell with coordinates (x,y).

bool isMoveValid(int x,int y); -> Performs the Bound Checking for the Move and check if the move cell is already occupied.

bool isBlank(int x,int y); -> Returns true if the cell with coordinates (x,y) is BLANK.

int checkWin(); -> check if any of the player has won or the game is tie and returns the game constants accordingly.

void print(); -> To print the board as a matrix of 3 x 3 on the screen.
