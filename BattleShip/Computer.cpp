#include "StdAfx.h"
#include "Computer.h"


Computer::Computer(void)
{
	playerField->GenerateShips();
}


Computer::~Computer(void)
{
}

void Computer::Fire()
{
	int randX = 0;
	int randY = 0;
	bool targetHit = true;
	srand(time(0));
	do
	{
		randX = 1+rand()%10;
		randY = 1+rand()%10;
		targetHit = enemyField->CheckHit(randX,randY);
		if(!targetHit)
			cout<<"\n Компьютер промахнулся! ";
		_sleep(500);
	}while(targetHit);
	_sleep(500);
	
}



