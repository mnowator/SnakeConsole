#include "Snake.h"

#include <algorithm>


Snake::Snake(unsigned length, DIRECTION dir) : length(length), dir( dir )
{
	for (unsigned i = 0; i < length; ++i)
		elements.push_back(Position(i+1, 1));
}


Snake::~Snake()
{
}

std::deque< Position > const& Snake::getElements()
{
	return elements;
}

bool Snake::extendSnake()
{
	if (dir == UP)
		elements.push_back(Position(elements.back().posX, elements.back().posY - 1));
	else if (dir == DOWN)
		elements.push_back(Position(elements.back().posX, elements.back().posY + 1));
	else if (dir == LEFT)
		elements.push_back(Position(elements.back().posX - 1, elements.back().posY));
	else if (dir == RIGHT)
		elements.push_back(Position(elements.back().posX + 1, elements.back().posY));

	return true;
}

bool Snake::growth()
{
	return extendSnake();
}

bool Snake::update()
{
	bool output = extendSnake();

	elements.pop_front();

	return output;
}

bool Snake::move(DIRECTION newDir)
{
	bool output = false;

	if ((dir == UP && newDir == DOWN) || (dir == DOWN && newDir == UP) || (dir == LEFT && newDir == RIGHT) || (dir == RIGHT && newDir == LEFT))
		std::reverse(elements.begin(), elements.end());
	
	dir = newDir;

	return output;
}

Position Snake::getNextPos()
{
	Position pos = elements.back();

	if (dir == UP)
		pos.posY -= 1;
	else if (dir == DOWN)
		pos.posY += 1;
	else if (dir == LEFT)
		pos.posX -= 1;
	else if (dir == RIGHT)
		pos.posX += 1;

	return pos;
}
