// BattleShip.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������
	Game game;
	game.StartGame();

	system("pause");
	return 0;
}

