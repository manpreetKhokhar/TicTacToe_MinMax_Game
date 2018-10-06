# mainGame.h
Constants RUNNING and END_GAME represent the current state of the game.

Declaration of class MainGame which handles all the events in the game and is responsible for actual game playing. This class represents 
a session of a game.

# mainGame.cpp
This implements the member functions of mainGame.h file.

Some important functions of this class are

gamePlay() -> It defines the action sequence in the game.

firstMoves(int aiPlayer) -> First two moves are performed using predefined cells

cellMapping(int cellNo) -> A cell number supplied by the user is mapped into coordinates of the (3 x 3) board.Provided for user convenience
