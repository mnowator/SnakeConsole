#include "Map.h"

#include <cmath>
#include <ctime>

Map::Map(std::string inputFileName ) : width(80), height(20)
{
	srand(time(NULL));

	std::ifstream inputFile;

	inputFile.open(inputFileName.c_str());

	if (inputFile.good())
	{
		for (unsigned i = 0; i < height; ++i)
		{
			std::vector< std::pair< Position, MAP_ELEMENT_TYPE > > row;
			map.push_back(row);

			for (unsigned j = 0; j < width; ++j)
			{
				char ch = inputFile.get();

				if (!inputFile.good()) throw WrongMapFormat();

				map.back().push_back(std::make_pair< Position, MAP_ELEMENT_TYPE >(Position(j, i), static_cast<MAP_ELEMENT_TYPE>(ch)));
			}
		}
	}
	else
	{
		throw WrongMapPath();
	}

	inputFile.close();
}


Map::~Map()
{
}

bool Map::rewriteSnake2map(std::deque< Position > const& elements)
{
	for (it2map itmap = map.begin(); itmap < map.end(); ++itmap)
		for (it2row itrow = (*itmap).begin(); itrow < (*itmap).end(); ++itrow)
			if ((*itrow).second == SNAKE) (*itrow).second = EMPTY;

	for (std::deque< Position >::const_iterator it=elements.begin(); it < elements.end(); ++it)
		map[(*it).posY][(*it).posX].second = SNAKE;

	return true;
}

bool Map::setPineapple()
{
	Position pos;
	bool output = false;

	while (true)
	{
		pos = Position(rand() % width, rand() % height);

		if (map[pos.posY][pos.posX].second == EMPTY)
		{
			pinaapple = pos;
			map[pos.posY][pos.posX].second = PINEAPPLE;
			return true;
		}
	}

	return false;
}

bool Map::nextPosPossible(Position pos)
{
	if (map[pos.posY][pos.posX].second == BORDER || map[pos.posY][pos.posX].second == SNAKE)
		return false;

	return true;
}

bool Map::nextPosIsPineapple(Position pos)
{
	if (map[pos.posY][pos.posX].second == PINEAPPLE)
		return false;

	return true;
}

std::string Map::displayMap()
{
	std::string output="";

	for (it2map itmap = map.begin(); itmap < map.end(); ++itmap)
	{
		for (it2row itrow = (*itmap).begin(); itrow < (*itmap).end(); ++itrow)
			output += static_cast<char>((*itrow).second);

		output += '\n';
	}


	return output;
}


