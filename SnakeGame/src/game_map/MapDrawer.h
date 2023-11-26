#pragma once

#include <iostream>
#include <functional>
#include <optional>
#include <vector>
#include <math.h>
#include "../core/Size.h"
#include "Utils.h"

class MapDrawer
{
public:
	static Size Size;


public:
	static std::vector<char> DrawMap(char borderSimbol, char innerSimbol) {
		std::vector<char> map;
		Utils::LoopMap(Size.Rows, Size.Columns, [&map, borderSimbol, innerSimbol](int currentRow, int currentColumn) {
			bool horizontalBorder = (currentRow == 0 || (Size.Rows - currentRow) == 1);
			bool verticalBorder = (currentColumn == 0 || (Size.Columns - currentColumn) == 1) && (currentRow != 0 || (Size.Rows - currentRow) == 1);

			if (horizontalBorder || verticalBorder) map.push_back(borderSimbol);
			else map.push_back(innerSimbol);

			});
		return map;
	}

	static std::vector<char> DrawMap2(char borderSimbol, char innerSimbol, std::optional<std::function<void(std::vector<char>*, int, int)>> func) {
		std::vector<char> map;
		Utils::LoopMap(Size.Rows, Size.Columns, [&map, borderSimbol, innerSimbol, func](int currentRow, int currentColumn) {
			bool horizontalBorder = (currentRow == 0 || (Size.Rows - currentRow) == 1);
			bool verticalBorder = (currentColumn == 0 || (Size.Columns - currentColumn) == 1) && (currentRow != 0 || (Size.Rows - currentRow) == 1);

			if (horizontalBorder || verticalBorder) map.push_back(borderSimbol);
			else if (func) func.value()(&map, currentRow, currentColumn);
			else map.push_back(innerSimbol);

			});
		return map;
	}
	
	static std::vector<char> DrawInMap(char simbol) {
		DrawMap2('*', ' ', [simbol](std::vector<char>* map, int currentRow, int currentColumn) {
			map->push_back(simbol);
		});
	}
};

