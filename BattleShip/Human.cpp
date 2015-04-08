#include "StdAfx.h"
#include "Human.h"


Human::Human(void)
{
	CreateShips();
}


Human::~Human(void)
{
}

void Human::CreateShips()
{
	char manual = ' ';
	cout<<"Ввести расположение кораблей самостоятельно? (y/n)";
	cin>>manual;
	if(manual == 'y')
		ManuallyPlacing();
	else if(manual == 'n')
		playerField->GenerateShips();
	cout<<"Все корабли успешно расставлены!"<<endl;
}

void Human::ManuallyPlacing()
{
	int row = 0;
	int col = 0;
	bool isHorizontal = 0;
	int shipType = 4;
	int count = 10;
	bool shipIsPlaced = true;
	char input = ' ';

	while(count)
	{
		cout<<"Установка "<<shipType<<"-х палубного корабля. \n";
		cout<<"Введите координаты начала корабля X Y: ";
		cin>>row>>col;
		cout<<"\nГоризонтально или вертикально расположить корабль? (h/v): ";
		cin>>input;
		if(input == 'v') isHorizontal = 0;
		else if(input == 'h') isHorizontal = 1;

		shipIsPlaced = playerField->PutShip(row, col, isHorizontal, shipType,count-1);//добавить: проверка на успешность
		if(shipIsPlaced) 
		{
			--count;
			if(count==9||count==7||count==4) --shipType;
		}
		else
			cout<<"Не удолось установить корабль! \n";
		
		playerField->ShowField();//test
	}
}

void Human::Fire()
{
	int row = 0;
	int col = 0;
	bool targetHit = true;
	do
	{
		cout<<"Ваш ход \n";
		cout<<"Введите координаты выстрела: ";
		cin>>row>>col;
		row++; col++; //т.к. пользователь вводит с 0, а у нас с 1
		targetHit = enemyField->CheckHit(row,col);
		if(!targetHit)
			cout<<"\n Промах! ";
	}while(targetHit);
	cout<<"Ход переходит сопернику."<<endl;
	_sleep(500);
}

//Field Human::GetPlayerField() const
//{return playerField;}

//void Human::SetEnemyField(Field enemy)
//{
//	enemyField = new Field(enemy);
//	enemyField->SetIsPlayerField(false);
//}
