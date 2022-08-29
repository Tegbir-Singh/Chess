#include "Engine.h"


//source file for engine class

//constructor
Engine::Engine() {
	pawnWhite.loadFromFile("pawnWhite.png");
	queenWhite.loadFromFile("queenWhite.png");
	kingWhite.loadFromFile("kingW.png");
	rookWhite.loadFromFile("rookW.png");
	bishopWhite.loadFromFile("bishopWhite.png");
	horseWhite.loadFromFile("horseWhite.png");

	pawnBlack.loadFromFile("pawnBlack.png");
	queenBlack.loadFromFile("queenBlack.png");
	kingBlack.loadFromFile("kingBlack.png");
	rookBlack.loadFromFile("rookBlack.png");
	bishopBlack.loadFromFile("bishopBlack.png");
	horseBlack.loadFromFile("horseBlack.png");


	pawnWhite.setSmooth(true);
	queenWhite.setSmooth(true);
	kingWhite.setSmooth(true);
	rookWhite.setSmooth(true);
	bishopWhite.setSmooth(true);
	horseWhite.setSmooth(true);

	pawnBlack.setSmooth(true);
	queenBlack.setSmooth(true);
	kingBlack.setSmooth(true);
	rookBlack.setSmooth(true);
	bishopBlack.setSmooth(true);
	horseBlack.setSmooth(true);
}


//render to screen
void Engine::RenderPeices(sf::RenderWindow& mainWindow, Tiles tileArr[8][8]) {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (tileArr[i][j].getType() != 0) {
				sf::Sprite piece;

				//white peices
				if ((tileArr[i][j].getType() ^ 15) == 0b1110) {
					piece.setTexture(pawnWhite);
					tileArr[i][j].setColor(1);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b1011) {
					piece.setTexture(rookWhite);
					tileArr[i][j].setColor(1);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b1100) {
					piece.setTexture(horseWhite);
					tileArr[i][j].setColor(1);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b1101) {
					piece.setTexture(bishopWhite);
					tileArr[i][j].setColor(1);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b1001) {
					piece.setTexture(kingWhite);
					tileArr[i][j].setColor(1);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b1010) {
					piece.setTexture(queenWhite);
					tileArr[i][j].setColor(1);
				}

				//black peices

				if ((tileArr[i][j].getType() ^ 15) == 0b0110) {
					piece.setTexture(pawnBlack);
					tileArr[i][j].setColor(0);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b0011) {
					piece.setTexture(rookBlack);
					tileArr[i][j].setColor(0);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b0100) {
					piece.setTexture(horseBlack);
					tileArr[i][j].setColor(0);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b0101) {
					piece.setTexture(bishopBlack);
					tileArr[i][j].setColor(0);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b0001) {
					piece.setTexture(kingBlack);
					tileArr[i][j].setColor(0);
				}
				else if ((tileArr[i][j].getType() ^ 15) == 0b0010) {
					piece.setTexture(queenBlack);
					tileArr[i][j].setColor(0);
				}

				
				piece.setPosition(tileArr[i][j].getPosition().x+10, tileArr[i][j].getPosition().y + 15);

				piece.setScale(0.5, 0.5);


				if ((tileArr[i][j].getType() ^ 15) == 0b1110 || (tileArr[i][j].getType() ^ 15) == 0b0110) {
					piece.setScale(0.4, 0.4);
					piece.setPosition(tileArr[i][j].getPosition().x +30, tileArr[i][j].getPosition().y + 20);

				}

				mainWindow.draw(piece);

			}

		}

	}
}

//render main grid

void Engine::RenderGrid(sf::RenderWindow& mainWindow, Tiles tileArr[8][8]) {

	sf::Vector2u size = mainWindow.getSize();
	sf::Vector2u pos{ 0,0 };

	unsigned int height = size.y / 8;
	unsigned int width = size.x / 8;

	sf::Vector2f mains;
	mains.x = height;
	mains.y = width;

	sf::Color color1{ sf::Color(235, 231, 185)};
	sf::Color color2{ sf::Color(189, 138, 104) };

	for (int i = 0; i < 8; i++) {
		pos.x = 0;
		for (int j = 0; j < 8; j++) {
			sf::Time x{};

			sf::RectangleShape tile;

			if (i % 2 == 0) {
				if (j % 2 == 0) {
					tile.setFillColor(color1);
				}
				else {
					tile.setFillColor(color2);
				}
			}
			else {

				if (j % 2 == 0) {
					tile.setFillColor(color2);
				}
				else {
					tile.setFillColor(color1);
				}
			}



			tile.setSize(mains);
			tile.setPosition(pos.x, pos.y);
			pos.x += width;
			sf::CircleShape marker;
			//ewfew
			if (tileArr[i][j].getMakred() == true) {

				
				marker.setFillColor(sf::Color(50,150,100));
				marker.setRadius(15);
				marker.setPosition(tileArr[i][j].position.x + (mainWindow.getSize().x/8 - marker.getRadius())/2-7, 
					tileArr[i][j].position.y + (mainWindow.getSize().y / 8 - marker.getRadius()) / 2-7);
				

				//tile.setFillColor(sf::Color(240, 217, 181, 200));
			}

			mainWindow.draw(tile);
			mainWindow.draw(marker);
			tileArr[i][j].position.x = pos.x -width;
			tileArr[i][j].position.y = pos.y;


		}

		pos.y += height;
	}
}