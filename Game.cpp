#include "Game.h"

#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <conio.h>

Game::Game() : gs(IN_MENU), result(0)
{
}


Game::~Game()
{
}

void Game::displayMenu()
{
	unsigned choose;

	if ( result > 10 )
		std::cout << "Your result: " << result << "\n";

	std::cout << "Choose map:\n"
		<< "1. Default\n";

	std::cin >> choose;

	if (choose == 1)
	{
		try
		{
			map = new Map("maps/default.map");
		}
		catch (WrongMapPath())
		{
			std::cout << "Error occur in map loading, please check path /maps/<map_name>, and restart aplication\n";
			return;
		}
		catch (...)
		{
			std::cout << "Please check your map format. It should be 80x20\n";
			return;
		}
		map->setPineapple();
		snake = new Snake;
		gs = IN_PROGRESS;
		result = 10;
	}
	else
	{
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		return;
	}
}

void Game::step()
{
	if (_kbhit())
	{
		char ch = _getch();
		
		if (ch == 'w' || ch == 's'|| ch == 'a' || ch == 'd')
			snake->move( static_cast<DIRECTION>( ch ));
	}
	
	if (!map->nextPosPossible(snake->getNextPos())) gs = IN_MENU;
	if (!map->nextPosIsPineapple(snake->getNextPos()))
	{
		++result;
		snake->growth();
		map->setPineapple();
	}
	snake->update();

	system("cls");
	map->rewriteSnake2map(snake->getElements());
	std::cout << map->displayMap();

	Sleep(100-std::log(result));
}

void Game::loop()
{
	while (true)
	{
		if ( gs == IN_MENU ) displayMenu();
		else step();
	}
}
