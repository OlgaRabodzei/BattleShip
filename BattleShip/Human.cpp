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
	cout<<"������ ������������ �������� ��������������? (y/n)";
	cin>>manual;
	if(manual == 'y')
		ManuallyPlacing();
	else if(manual == 'n')
		playerField->GenerateShips();
	cout<<"��� ������� ������� �����������!"<<endl;
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
		cout<<"��������� "<<shipType<<"-� ��������� �������. \n";
		cout<<"������� ���������� ������ ������� X Y: ";
		cin>>row>>col;
		cout<<"\n������������� ��� ����������� ����������� �������? (h/v): ";
		cin>>input;
		if(input == 'v') isHorizontal = 0;
		else if(input == 'h') isHorizontal = 1;

		shipIsPlaced = playerField->PutShip(row, col, isHorizontal, shipType,count-1);//��������: �������� �� ����������
		if(shipIsPlaced) 
		{
			--count;
			if(count==9||count==7||count==4) --shipType;
		}
		else
			cout<<"�� ������� ���������� �������! \n";
		
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
		cout<<"��� ��� \n";
		cout<<"������� ���������� ��������: ";
		cin>>row>>col;
		row++; col++; //�.�. ������������ ������ � 0, � � ��� � 1
		targetHit = enemyField->CheckHit(row,col);
		if(!targetHit)
			cout<<"\n ������! ";
	}while(targetHit);
	cout<<"��� ��������� ���������."<<endl;
	_sleep(500);
}

//Field Human::GetPlayerField() const
//{return playerField;}

//void Human::SetEnemyField(Field enemy)
//{
//	enemyField = new Field(enemy);
//	enemyField->SetIsPlayerField(false);
//}
