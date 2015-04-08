#pragma once
#include <cstdlib>
#include <ctime>
#include "Ship.h"

struct FieldCell
{
	char symbol;
	Ship *ship;
	FieldCell()	{symbol = ' '; ship = 0;}
};

class Field
{
	static const short sizeField = 11;
	static const short numberOfShips = 10;
	FieldCell **matrix;
	bool myField;
	Ship *listOfShips;

	void UpdateMatrix();
public:
	Field();
	Field(Field const&);
	~Field(void);
	void GenerateShips();
	bool PutShip(int,int,bool,int,int);
	bool CheckHit(int,int);
	bool GetIsPlayerField() const;
	void SetIsPlayerField(bool);
	
	//int GetSizeField() const;
	void ShowField() ;
	bool CheckIsAllFired();
};



