#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tiles.h"

//header file of engine class

class Engine
{
public:
	
	sf::Texture queenWhite;
	sf::Texture kingWhite;
	sf::Texture rookWhite;
	sf::Texture bishopWhite;
	sf::Texture pawnWhite;
	sf::Texture horseWhite;

	sf::Texture queenBlack;
	sf::Texture kingBlack;
	sf::Texture rookBlack;
	sf::Texture bishopBlack;
	sf::Texture pawnBlack;
	sf::Texture horseBlack;


	void RenderPeices(sf::RenderWindow& mainWindow, Tiles tileArr[8][8]);
	void RenderGrid(sf::RenderWindow& mainWindow, Tiles tileArr[8][8]);
	Engine();

private:

};
