#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.h"

//header file of tiles class


class Tiles
{
public:
	int getType();	
	void setType(int);
	bool isSeleted();
	void setSelected(bool);
	void setPosition(sf::Vector2u);
	sf::Vector2u getPosition();
	bool getMakred();
	void setMarked(bool);
	sf::Vector2u position{};

	void setColor(int);
	int getColor();

	void movement(sf::RenderWindow& mainWindow, Tiles tileArr[8][8], int* , int*, int* moveCount);
	void move(sf::RenderWindow& mainWindow,Tiles tileArr[8][8], int*, int*, int *moveCount);
	void mark(Tiles tileArr[8][8], int,int);
	bool inBounds(int, int);

	bool check(Tiles point);

	void resetMark(Tiles tileArr[8][8]);

private:
	bool inChceck;
	int type;
	bool selected;
	bool marked;
	int color;
};