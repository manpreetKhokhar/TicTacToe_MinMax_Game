The AI.h file contains the declaration of two classes- Move class and AI class.
The Move class represents the move in the game, which consists of cell coordinates of the board where a symbol has to be inserted.
Additionaly, it also has score as its data member.This is actually for the Minmax algorithm which uses the move score to judge which is 
a better move (Out of many possibilities) at the particular level of game tree.
The AI.cpp implements the functions of AI.h. The makeMove() function performs the move of AI agent by getting the best move from the 
minMaxMove() function. The minMaxMove() actually implements the minMax algorithm.
