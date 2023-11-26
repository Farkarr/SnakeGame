//#include <iostream>
//#include <vector>
#include "game_map/Game.h"
#include "snake/Snake.h"
#include "../Input.h"

bool gameOver;
Game game;
Snake snake(1);
int moveVertical = 10;
int moveHorizontal = 4;

void Setup() {
	gameOver = false;
	Utils::ShowConsoleCursor(false);
	game.GenerateMap(25, 40, '@');
	//game.DrawInMap(10, 25, &snake, "horizontal", "left");
}

void Draw() {
	game.RenderMap();
	game.DrawInMap(moveVertical, moveHorizontal, &snake, "horizontal", "left");
}

void Input() {
	if (Input::IsKeyPressed('Q')) gameOver = true;
	if (Input::IsKeyPressed('D')) {
		moveHorizontal++;
	}
	if (Input::IsKeyPressed('A')) {
		moveHorizontal--;
	}
	if (Input::IsKeyPressed('W')) {
		moveVertical--;
	}
	if (Input::IsKeyPressed('S')) {
		moveVertical++;
	}
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