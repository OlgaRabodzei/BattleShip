#include "StdAfx.h"
#include "Ship.h"


Ship::Ship(void)
{
	isDead = false;
	type = -1;
	hits = 0;
}

Ship::~Ship(void){}

bool Ship::GetIsDead()const {return isDead;}

void Ship::SetIsDead(bool dead) {isDead = dead;}

int Ship::GetType()const {return type;}

void Ship::SetType(int typeShip){type = typeShip;}

void Ship::AddHit() 
{
	++hits;
	if (type == hits) isDead = true;
}
