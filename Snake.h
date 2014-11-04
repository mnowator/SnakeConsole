#pragma once
#pragma once

#include <deque>
#include "Position.h"

enum DIRECTION { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

class Snake
{
private:
	unsigned length;
	std::deque< Position > elements;
	DIRECTION dir;

	bool extendSnake();

public:
	Snake( unsigned length=10, DIRECTION dir=RIGHT );
	~Snake();

	std::deque< Position > const& getElements();

	bool growth();
	bool update();
	bool move(DIRECTION newDir);
	Position getNextPos();
};

