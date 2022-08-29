#include "Tiles.h"

//source file for tiles class


//set type and get type functions:
int Tiles::getType() {
	return this->type;
}

void Tiles::setType(int type) {
	this->type = type;
}

bool Tiles::isSeleted() {
	return this->selected;
}

void Tiles::setSelected(bool choice) {
	this->selected = choice;
}

void Tiles::setPosition(sf::Vector2u pos) {
	this->position = pos;
}

void Tiles::setMarked(bool choice) {
	this->marked = choice;
}

bool Tiles::getMakred() {
	return this->marked;
}

sf::Vector2u Tiles::getPosition() {
	return this->position;
}

int Tiles::getColor() {
	return this->color;
}

void Tiles::setColor(int color) {
	this->color = color;
}

//main movement function
void Tiles::movement(sf::RenderWindow& mainWindow, Tiles tileArr[8][8], int *x, int *y, int* moveCount) {
	sf::Mouse mainMouse;

	float width = mainWindow.getSize().x / 8;
	float height = mainWindow.getSize().y / 8;


	sf::Vector2i MousePosition = mainMouse.getPosition(mainWindow);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {
				//check intersection 
				
				if (MousePosition.x >= tileArr[i][j].position.x && MousePosition.x <= tileArr[i][j].position.x + width
					&& MousePosition.y >= tileArr[i][j].position.y && MousePosition.y <= tileArr[i][j].position.y + height
					&& tileArr[i][j].type != 0 && tileArr[i][j].marked != true) {

					tileArr[i][j].selected = true;

					mark(tileArr, i, j);
					

					*x = i;
					*y = j;

				}
				else if(MousePosition.x >= tileArr[i][j].position.x && MousePosition.x <= tileArr[i][j].position.x + width
					&& MousePosition.y >= tileArr[i][j].position.y && MousePosition.y <= tileArr[i][j].position.y + height
					&& tileArr[i][j].type == 0 && tileArr[i][j].marked != true){
					mark(tileArr, -1, -1);
				}
				

			}

		}


	}


}

//function to move a piece
void Tiles::move(sf::RenderWindow& mainWindow, Tiles tileArr[8][8], int* x, int* y, int *moveCount) {

	if (*x == -1 && *y == -1) {
		return;
	}

	sf::Mouse mainMouse;

	float width = mainWindow.getSize().x / 8;
	float height = mainWindow.getSize().y / 8;

	int movex{};
	int movey{};
	sf::Vector2i MousePosition = mainMouse.getPosition(mainWindow);

	//on click 
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {
				//check intersection 
				if (MousePosition.x >= tileArr[i][j].position.x && MousePosition.x <= tileArr[i][j].position.x + width
					&& MousePosition.y >= tileArr[i][j].position.y && MousePosition.y <= tileArr[i][j].position.y + height
					) {
					
					//move accordingly 
					tileArr[i][j].selected = true;
					
					if (*moveCount % 2 == 0) {
						if (tileArr[i][j].marked && tileArr[*x][*y].type <7 ) {

							tileArr[i][j] = tileArr[*x][*y];
							tileArr[*x][*y].type = 0;
							tileArr[*x][*y].color = 3;
							*moveCount = *moveCount + 1;
							mark(tileArr, -1, -1);
						}
					}
					else {

						if (tileArr[i][j].marked && tileArr[*x][*y].type > 7) {

							tileArr[i][j] = tileArr[*x][*y];
							tileArr[*x][*y].type = 0;
							tileArr[*x][*y].color = 3;
							*moveCount = *moveCount + 1;
							mark(tileArr, -1, -1);
								
							
						}


					}
									

				}

			}

		}

	}
}

//mark tile on selected piece,
//different for each piece
void Tiles::mark(Tiles tileArr[8][8], int i, int j) {
	
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			tileArr[x][y].marked = false;
		}
	}

	if (i == -1 && j == -1) {
		return;
	}
	else {
		//black pawn:
		if (tileArr[i][j].type == 9) {

			if (i == 1) {

				for (int e = 1; e < 3; e++) {

					if (tileArr[i + e][j].type == 0 && inBounds(i + e, j)) {
						tileArr[i + e][j].marked = true;

						if (tileArr[i + e][j].type != 0) {
							break;
						}
					}
					else
					{
						break;
					}

				}
			}
			else {
				if (tileArr[i + 1][j].type == 0 && inBounds(i + 1, j)) {
					tileArr[i + 1][j].marked = true;

				}
			}


			if (tileArr[i + 1][j + 1].type != 0 && inBounds(i + 1, j + 1) && tileArr[i][j].color != tileArr[i + 1][j + 1].color) {
				tileArr[i + 1][j+1].marked = true;

			}

			if (tileArr[i + 1][j -1 ].type != 0 && inBounds(i + 1, j -1 ) && tileArr[i][j].color != tileArr[i + 1][j -1].color) {
				tileArr[i + 1][j -1 ].marked = true;

			}

		}


		//white pawn:
		if (tileArr[i][j].type == 1) {
			
			if (i == 6) {

				for (int e = 1; e < 3; e++) {

					if (tileArr[i - e][j].type == 0 && inBounds(i - e, j)) {
						tileArr[i - e][j].marked = true;

						if (tileArr[i - e][j].type != 0) {
							break;
						}
					}
					else
					{
						break;
					}

				}
			}
			else {
				if (tileArr[i - 1][j].type == 0 && inBounds(i-1, j)) {
					tileArr[i - 1][j].marked = true;

				}
			}

			if (tileArr[i -1 ][j + 1].type != 0 && inBounds(i - 1, j + 1) && tileArr[i][j].color != tileArr[i - 1][j + 1].color) {
				tileArr[i - 1][j + 1].marked = true;

			}

			if (tileArr[i - 1][j - 1].type != 0 && inBounds(i - 1, j - 1) && tileArr[i][j].color != tileArr[i - 1][j - 1].color) {
				tileArr[i - 1][j - 1].marked = true;

			}

		}

		//horses: 

		if (tileArr[i][j].type == 3 || tileArr[i][j].type == 11) {


			if (tileArr[i - 2][j + 1].color != tileArr[i][j].color && inBounds(i - 2, j + 1)) {
				tileArr[i - 2][j + 1].marked = true;


			}

			if (tileArr[i - 2][j - 1].color != tileArr[i][j].color && inBounds(i - 2, j - 1)) {
				tileArr[i - 2][j - 1].marked = true;
			}

			if (tileArr[i + 2][j + 1].color != tileArr[i][j].color && inBounds(i + 2, j + 1)) {
				tileArr[i + 2][j + 1].marked = true;
			}

			if (tileArr[i + 2][j - 1].color != tileArr[i][j].color && inBounds(i + 2, j - 1)) {
				tileArr[i + 2][j - 1].marked = true;
			}

			if (tileArr[i - 1][j + 2].color != tileArr[i][j].color && inBounds(i - 1, j + 2)) {
				tileArr[i - 1][j + 2].marked = true;
			}

			if (tileArr[i - 1][j - 2].color != tileArr[i][j].color && inBounds(i - 1, j - 2)) {
				tileArr[i - 1][j - 2].marked = true;
			}


			if (tileArr[i + 1][j + 2].color != tileArr[i][j].color && inBounds(i + 1, j + 2)) {
				tileArr[i + 1][j + 2].marked = true;
			}

			if (tileArr[i + 1][j - 2].color != tileArr[i][j].color && inBounds(i + 1, j - 2)) {
				tileArr[i + 1][j - 2].marked = true;
			}

			//bishops

		}

		//queens:

		if (tileArr[i][j].type == 5 || tileArr[i][j].type == 13) {

			for (int e = 1; e < 8; e++) {

				if (tileArr[i - e][j].color != tileArr[i][j].color && inBounds(i - e, j)) {
					tileArr[i - e][j].marked = true;

					if (tileArr[i - e][j].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}

			}


			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j].color != tileArr[i][j].color && inBounds(i + e, j)) {
					tileArr[i + e][j].marked = true;

					if (tileArr[i + e][j].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i][j + e].color != tileArr[i][j].color && inBounds(i, j + e)) {
					tileArr[i][j + e].marked = true;

					if (tileArr[i][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i][j - e].color != tileArr[i][j].color && inBounds(i, j - e)) {
					tileArr[i][j - e].marked = true;

					if (tileArr[i][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i - e][j - e].color != tileArr[i][j].color && inBounds(i - e, j - e)) {
					tileArr[i - e][j - e].marked = true;

					if (tileArr[i - e][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j + e].color != tileArr[i][j].color && inBounds(i + e, j + e)) {
					tileArr[i + e][j + e].marked = true;

					if (tileArr[i + e][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j - e].color != tileArr[i][j].color && inBounds(i + e, j - e)) {
					tileArr[i + e][j - e].marked = true;

					if (tileArr[i + e][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i - e][j + e].color != tileArr[i][j].color && inBounds(i - e, j + e)) {
					tileArr[i - e][j + e].marked = true;

					if (tileArr[i - e][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		//bishops:

		if (tileArr[i][j].type == 2 || tileArr[i][j].type == 10) {
			for (int e = 1; e < 8; e++) {
				if (tileArr[i - e][j - e].color != tileArr[i][j].color && inBounds(i - e, j - e)) {
					tileArr[i - e][j - e].marked = true;

					if (tileArr[i - e][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j + e].color != tileArr[i][j].color && inBounds(i + e, j + e)) {
					tileArr[i + e][j + e].marked = true;

					if (tileArr[i + e][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j - e].color != tileArr[i][j].color && inBounds(i + e, j - e)) {
					tileArr[i + e][j - e].marked = true;

					if (tileArr[i + e][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i - e][j + e].color != tileArr[i][j].color && inBounds(i - e, j + e)) {
					tileArr[i - e][j + e].marked = true;

					if (tileArr[i - e][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		//rooks:

		if (tileArr[i][j].type == 4 || tileArr[i][j].type == 12) {
			for (int e = 1; e < 8; e++) {

				if (tileArr[i - e][j].color != tileArr[i][j].color && inBounds(i - e, j)) {
					tileArr[i - e][j].marked = true;

					if (tileArr[i - e][j].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}

			}


			for (int e = 1; e < 8; e++) {
				if (tileArr[i + e][j].color != tileArr[i][j].color && inBounds(i + e, j)) {
					tileArr[i + e][j].marked = true;

					if (tileArr[i + e][j].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i][j + e].color != tileArr[i][j].color && inBounds(i, j + e)) {
					tileArr[i][j + e].marked = true;

					if (tileArr[i][j + e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}

			for (int e = 1; e < 8; e++) {
				if (tileArr[i][j - e].color != tileArr[i][j].color && inBounds(i, j - e)) {
					tileArr[i][j - e].marked = true;

					if (tileArr[i][j - e].type != 0) {
						break;
					}
				}
				else
				{
					break;
				}
			}
		}

		//kings

		if (tileArr[i][j].type == 6 || tileArr[i][j].type == 14) {

			if (tileArr[i - 1][j].color != tileArr[i][j].color && inBounds(i - 1, j)) {
				tileArr[i - 1][j].marked = true;
			}

			if (tileArr[i + 1][j].color != tileArr[i][j].color && inBounds(i + 1, j)) {
				tileArr[i + 1][j].marked = true;
			}

			if (tileArr[i][j + 1].color != tileArr[i][j].color && inBounds(i, j + 1)) {
				tileArr[i][j + 1].marked = true;
			}

			if (tileArr[i][j - 1].color != tileArr[i][j].color && inBounds(i, j - 1)) {
				tileArr[i][j - 1].marked = true;
			}

			if (tileArr[i + 1][j - 1].color != tileArr[i][j].color && inBounds(i + 1, j - 1)) {
				tileArr[i + 1][j - 1].marked = true;
			}

			if (tileArr[i - 1][j - 1].color != tileArr[i][j].color && inBounds(i - 1, j - 1)) {
				tileArr[i - 1][j - 1].marked = true;
			}

			if (tileArr[i + 1][j + 1].color != tileArr[i][j].color && inBounds(i + 1, j + 1)) {
				tileArr[i + 1][j + 1].marked = true;
			}

			if (tileArr[i - 1][j + 1].color != tileArr[i][j].color && inBounds(i - 1, j + 1)) {
				tileArr[i - 1][j + 1].marked = true;
			}




		}

	}


}

bool Tiles::inBounds(int x, int y) {
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
		return true;
	}
	return false;
}

bool Tiles::check(Tiles point) {
	return false;
}

