#pragma once

#include "Snake.h"
#include "Map.h"



class Game
{
private:
	enum GAME_STATE { IN_PROGRESS, IN_MENU };

	GAME_STATE gs;

	Map* map;
	Snake* snake;

	unsigned result;

	void displayMenu();
	void step();

public:

	void loop();

	Game();
	~Game();
};

