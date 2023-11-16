#pragma once

#include <iostream>
#include <vector>

class GameMap
{
private:
	std::vector<char> GetMap(int rows, int columns, char borderSimbol = '*', char innerSimbol = ' ') {
		std::vector<char> map;

		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				bool horizontalBorder = (i == 0 || (rows - i) == 1);
				bool verticalBorder = (y == 0 || (columns - y) == 1) && (i != 0 || (rows - i) == 1);
				if (horizontalBorder || verticalBorder) {
					map.push_back(borderSimbol);
				}
				else {
					map.push_back(innerSimbol);
				}
			}
			std::cout << std::endl;
		}
		return map;
	}
public:
	std::vector<char> Map{' ', ' '};

	void GenerateMap(int rows, int columns) {
		Map = GetMap(25, 40);
		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				int index = i * columns + y;
				std::cout << Map[index];
			}
			std::cout << std::endl;
		}
	}
};

