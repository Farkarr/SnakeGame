#pragma once

#include <vector>
#include "../core/GameObject.h"

class Snake : public GameObject
{
public:
	Snake(int tail)
	{
		SetShape(tail);
	}

	void SetShape(int tail) {
		for (int i = 0; i < tail; i++) {
			Shape.push_back('*');
		}
	}
};

