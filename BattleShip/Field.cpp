#include "StdAfx.h"
#include "Field.h"


Field::Field()
{
	//выделение пам€ти
	matrix = new FieldCell * [sizeField];
	for(int i=0; i<sizeField; ++i)
		matrix[i] = new FieldCell[sizeField];
	listOfShips = new Ship[numberOfShips];
	//начальна€ инициализаци€
	myField = true;
	matrix[0][0].symbol = '\\';
	for(int i=1; i<sizeField;++i)
	{
		matrix[i][0].symbol = 'a'+(i-1);
		matrix[0][i].symbol = '0'+(i-1);
	}
	/*for(int i=1; i<sizeField;++i)
		for(int j=1; j<sizeField;++j)
			matrix[i][j]=' ';*/
}

Field::Field(Field const& f)
{
	//выделение пам€ти
	matrix = new FieldCell * [sizeField];
	for(int i=0; i<sizeField; ++i)
		matrix[i] = new FieldCell[sizeField];
	listOfShips = new Ship[numberOfShips];
	//копирование матрицы
	for(int i=0;i<sizeField; ++i)
		for(int j=0;j<sizeField; ++j)
		{
			matrix[i][j].ship = f.matrix[i][j].ship;
			matrix[i][j].symbol = f.matrix[i][j].symbol;
		}
	//копирование списка кораблей
	for(int i=0;i<numberOfShips; ++i)
		listOfShips[i] = f.listOfShips[i];
	myField = true;
}


Field::~Field(void)
{
	if(matrix == 0 || listOfShips == 0) return;
	for(int i=0; i<sizeField; ++i)
		delete[] matrix[i];
	delete[] matrix;
	delete[] listOfShips;
	matrix = 0;
	listOfShips = 0;
}

void Field::GenerateShips()
{
	int randX = 0;
	int randY = 0;
	bool isHorizontal = 0;
	int shipType = 4;
	int count = 10;
	bool shipIsPlaced = true;

	srand(time(0));
	while(count)
	{
		randX = 1+rand()%10;
		randY = 1+rand()%10;
		isHorizontal = rand()%2;
		shipIsPlaced = PutShip(randX, randY, isHorizontal, shipType,count-1);//добавить: проверка на успешность
		if(shipIsPlaced) 
		{
			--count;
			if(count==9||count==7||count==4) --shipType;
		}
		
		//ShowField();//test
	}

}

bool Field::PutShip( int row, int col, bool isHorizontal, int shipType, int count)
{
	if(isHorizontal)
	{
		for(int i=0; i<shipType; ++i)
		{
			if((col+i)>=sizeField || matrix[row][col+i].symbol != ' ') 
				return false;
			if(
				((row-1)>0 && matrix[row-1][col+i].symbol != ' ') || 
				((row+1)<sizeField && matrix[row+1][col+i].symbol != ' ') || 
				((col+i-1)>0 && matrix[row][col+i-1].symbol != ' ') || 
				((col+i+1)<sizeField && matrix[row][col+i+1].symbol != ' ')
				)
				return false;
		}
		listOfShips[count].SetType(shipType);
		listOfShips[count].SetIsDead(false);
		for(int i=0; i<shipType; ++i) 
		{
			matrix[row][col+i].symbol = shipType;
			matrix[row][col+i].ship = & listOfShips[count];
		}
	}
	else
	{
		for(int i=0; i<shipType; ++i)
		{
			if((row+i)>=sizeField || matrix[row+i][col].symbol != ' ') 
				return false;
			if(
				((row+i-1)>0 && matrix[row+i-1][col].symbol != ' ') || 
				((row+i+1)<sizeField && matrix[row+i+1][col].symbol != ' ') || 
				((col-1)>0 && matrix[row+i][col-1].symbol != ' ') || 
				((col+1)<sizeField && matrix[row+i][col+1].symbol != ' ')
				)
				return false;
		}
		listOfShips[count].SetType(shipType);
		listOfShips[count].SetIsDead(false);
		for(int i=0; i<shipType; ++i)
		{
			matrix[row+i][col].symbol = shipType;
			matrix[row+i][col].ship = & listOfShips[count];
		}
	}
	return true;
}

bool Field::CheckHit(int row,int col)
{
	if(matrix[row][col].symbol == 'H' || matrix[row][col].symbol == '*' || matrix[row][col].symbol == 'D')
	{
		cout<<"¬ы сюда уже стрел€ли! \n";
		return true;
	}
	else if(matrix[row][col].symbol == 1)
	{
		matrix[row][col].symbol = 'D';//убит
		matrix[row][col].ship->SetIsDead(true);
		cout<<"”бит!";
		return true;
	}
	else if(matrix[row][col].symbol >= 2 && matrix[row][col].symbol < 5)
	{
		matrix[row][col].ship->AddHit();
		if(matrix[row][col].ship->GetIsDead())
		{
			matrix[row][col].symbol = 'D';
			cout<<"”бит!";
		}
		else
		{
			matrix[row][col].symbol = 'H';
			cout<<"–анен.";
		}
		return true;
	}
	else matrix[row][col].symbol = '*';
	return false;
}

void Field::ShowField() 
{
	UpdateMatrix();
	for(int i=0; i<sizeField;++i)
	{
		for(int j=0; j<sizeField;++j)
		{
			if(i==0 || j==0)
				cout<<matrix[i][j].symbol<<' ';
			else if(myField || (matrix[i][j].symbol!=1 && matrix[i][j].symbol!=2 && matrix[i][j].symbol!=3 && matrix[i][j].symbol!=4))
				cout<<matrix[i][j].symbol<<' ';
			else
				cout<<"  ";
		}
		cout<<"\n";
	}
}

bool  Field::GetIsPlayerField() const {return myField;}

void  Field::SetIsPlayerField(bool isPlayersField){ myField = isPlayersField;}

bool Field::CheckIsAllFired()
{
	if(myField) return false; //если по ошибке пришло свое поле
	////провер€ем не осталось ли клеток с корабл€ми
	//for(int i=0; i<sizeField; ++i)
	//	for(int j=0; j<sizeField;++j)
	//		if(matrix[i][j]==1 || matrix[i][j]==2 || matrix[i][j]==3 || matrix[i][j]==4)
	//			return false;
	for(int i=0; i<numberOfShips; ++i)
		if(!listOfShips[i].GetIsDead()) return false;
	return true;
}

void Field::UpdateMatrix()
{
	for(int i=0; i<sizeField; ++i)
		for(int j=0; j<sizeField; ++j)
			if(matrix[i][j].ship!= 0 && matrix[i][j].ship->GetIsDead())
			{
				matrix[i][j].symbol = 'D';
				if(!myField)
				{
					if(matrix[i-1][j].ship==0)	matrix[i-1][j].symbol = '*';
					if(matrix[i+1][j].ship==0)	matrix[i+1][j].symbol = '*';
					if(matrix[i][j-1].ship==0)	matrix[i][j-1].symbol = '*';
					if(matrix[i][j+1].ship==0)	matrix[i][j+1].symbol = '*';
				}
			}
}





//int Field::GetSizeField() const {return sizeField;}

