#pragma once

#include <iostream>
#include <functional>
#include <optional>

class Utils
{
public:
	static void LoopMap(int rows, int columns, std::optional<std::function<void(int, int)>> func = nullptr) {
		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				if (func) func.value()(i, y);
			}
			std::cout << std::endl;
		}
	}
};

