#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <optional>
#include <math.h>
#include <conio.h> 

#include "MapDrawer.h"

class GameMap
{
private:
	int _rows;
	int _columns;
	int _borderSimbol;

private:
	void LoopMap(int rows, int columns, std::optional<std::function<void(int, int)>> func = nullptr) {
		for (int i = 0; i < rows; i++)
		{
			for (int y = 0; y < columns; y++)
			{
				if(func) func.value()(i, y);
			}
			std::cout << std::endl;
		}
	}

	std::vector<char> DrawMap(char borderSimbol, char innerSimbol) {
		std::vector<char> map;
		LoopMap(_rows, _columns, [&map, this, borderSimbol, innerSimbol](int currentRow, int currentColumn) {
			bool horizontalBorder = (currentRow == 0 || (_rows - currentRow) == 1);
			bool verticalBorder = (currentColumn == 0 || (_columns - currentColumn) == 1) && (currentRow != 0 || (_rows - currentRow) == 1);

			if (horizontalBorder || verticalBorder) map.push_back(borderSimbol);
			else map.push_back(innerSimbol);

			});
		return map;
	}
	
	
public:
	std::vector<char> Map;

public:
	

	void RenderMap() {
		system("cls");
		LoopMap(_rows, _columns, [this](int currentRow, int currentColumn) {
			int index = currentRow * _columns + currentColumn;
			std::cout << Map[index];
		});
	}

	void GenerateMap(int rows, int columns, char borderSimbol = '*', char innerSimbol = ' ') {
		_rows = rows;
		_columns = columns;
		_borderSimbol = borderSimbol;
		Map = DrawMap(borderSimbol, innerSimbol);
		RenderMap();
	}

	void DrawInMap(int row, int column, char simbol) {
		LoopMap(_rows, _columns, [this, row, column, simbol](int currentRow, int currentColumn) {
			if (row == currentRow && column == currentColumn) {
				int index = currentRow * _columns + currentColumn;
				Map[index] = simbol;
			}
			});
	}

	void DrawInMap(int row, int column, std::vector<char> simbols, std::string orientation, std::string direction) {
		LoopMap(_rows, _columns, [this, row, column, simbols, orientation, direction](int currentRow, int currentColumn) {
			if (row == currentRow && column == currentColumn) {
				int index;
				int currentRowAux = currentRow;
				int currentColumnAux = currentColumn;
				for (int i = 0; i < simbols.size(); i++)
				{
					if (orientation == "vertical") {
						index = currentRowAux * _columns + currentColumn;
						if (direction == "top") {
							currentRowAux--;
						}
						else if (direction == "bottom") {
							currentRowAux++;
						}
						Map[index] = simbols[i];
					}
					else if (orientation == "horizontal") {
						index = currentRow * _columns + currentColumnAux;
						if (direction == "left") {
							currentColumnAux--;
						}
						else if (direction == "right") {
							currentColumnAux++;
						}
						Map[index] = simbols[i];
					}
				}
			}
			});
	}
	
	void SpawnMiddle(char innerSymbol) {
		if (Map.size() == 0) return;

		int rowMiddle = _rows / 2;
		int columnMiddle = _columns / 2;

		DrawInMap(rowMiddle, columnMiddle, innerSymbol);
	}
};

