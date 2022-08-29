#pragma once
#include <SFML/Graphics.hpp>

//header file for peices class
class Pieces
{
public:

	void setType(int);
	int getType();
	void possibleMoves(int board[8][8]);

private:
	int type;

};
