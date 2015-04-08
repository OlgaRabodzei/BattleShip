// BattleShip.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали
	Game game;
	game.StartGame();

	system("pause");
	return 0;
}

