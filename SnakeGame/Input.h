#pragma once

#include <Windows.h>

class Input
{
public:
	static bool IsKeyPressed(char key) {
		if (GetKeyState(key) & 0x8000) return true;
		else return false;

	}
};

