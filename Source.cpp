#include <iostream>
#include <SFML/Graphics.hpp>

//header files 
#include "Tiles.h"
#include "Pieces.h"
#include "Engine.h"


//function declerations

int board[8][8] = {
{12,11,10,13,14,10,11,12},
{9,9,9,9,9,9,9,9},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,1},
{4,3,2,5,6,2,3,4}
};

int main() {
	
	int SelX{-1};
	int SelY{-1};
	int moveCount{};
	//main window
	sf::RenderWindow mainWindow();

	Tiles tileArr[8][8];
	Tiles mainBoard;
	Engine engine;


	
	sf::RenderWindow MainWindow(sf::VideoMode(900, 900), "Chess Game");

	//start the board
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tileArr[i][j].setType(board[i][j]);

		}
	}

	//main init stage

	MainWindow.clear();
	engine.RenderGrid(MainWindow, tileArr);
	engine.RenderPeices(MainWindow, tileArr);
	MainWindow.display();
	mainBoard.movement(MainWindow, tileArr, &SelX, &SelY, &moveCount);
	mainBoard.move(MainWindow, tileArr, &SelX, &SelY,&moveCount);

	//main game loop
	while (MainWindow.isOpen())
	{
		sf::Event event;
		while (MainWindow.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed) {
				MainWindow.close();
			}

		}
		
		//check action 
		if (event.type == sf::Event::MouseButtonPressed) {
			MainWindow.clear();
			engine.RenderGrid(MainWindow, tileArr);
			engine.RenderPeices(MainWindow, tileArr);
			MainWindow.display();
			mainBoard.movement(MainWindow, tileArr, &SelX, &SelY, &moveCount);
			mainBoard.move(MainWindow, tileArr, &SelX, &SelY, &moveCount);
		}
				
			
		
	}


}


