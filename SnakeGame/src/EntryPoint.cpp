//#include <iostream>
//#include <vector>
#include "game_map/GameMap.h"
bool gameOver;
GameMap gameMap;

void Setup() {
	gameOver = false;
	gameMap.GenerateMap(25, 40, '@');
	gameMap.DrawInMap(10, 1, {'*', '*', '*', '*'}, "horizontal", "right");
	gameMap.RenderMap();


}

void Draw() {
	gameMap.RenderMap();

}

void Input() {

}

void Logic() {

}

void ExitGame() {

}

int main() {
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
	ExitGame();
}