//#include <iostream>
//#include <vector>
#include "GameMap.h"
bool gameOver;
GameMap gameMap;

void Setup() {
	gameOver = false;
	gameMap.GenerateMap(25, 40);
}

void Draw() {

}

void Input() {

}

void Logic() {

}

void ExitGame() {

}

int main() {
	Setup();
	/*while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}*/
	ExitGame();
}