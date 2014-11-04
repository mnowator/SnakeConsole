#pragma once

#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <deque>
#include "Position.h"

class WrongMapPath
{
public:
	WrongMapPath()
	{}
};

class WrongMapFormat
{
public:
	WrongMapFormat()
	{}
};

class Map
{
private:
	enum MAP_ELEMENT_TYPE { BORDER = '+', SNAKE = 'o', PINEAPPLE = '$', EMPTY = ' ' };

	const unsigned width;
	const unsigned height;

	Position pinaapple;

	typedef std::vector< std::vector< std::pair< Position, MAP_ELEMENT_TYPE > > >::iterator it2map;
	typedef std::vector< std::pair< Position, MAP_ELEMENT_TYPE > >::iterator it2row;

	std::vector< std::vector< std::pair< Position, MAP_ELEMENT_TYPE > > > map;

public:
	bool rewriteSnake2map(std::deque< Position > const& elements);
	bool setPineapple();
	bool nextPosPossible(Position pos);
	bool nextPosIsPineapple(Position pos);
	std::string displayMap();

	Map();
	Map( std::string inputFileName );
	~Map();
};

