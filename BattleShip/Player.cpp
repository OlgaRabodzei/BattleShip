#include "StdAfx.h"
#include "Player.h"


Player::Player(void)
{
	playerField = new Field();
	enemyField = 0;
	//enemyField = new Field();
}


Player::~Player(void)
{
	delete playerField;
	if(enemyField!=0)	delete enemyField;
}

void Player::ShowFields()
{
	playerField->ShowField();
	enemyField->ShowField();
}

bool Player::IsWinner()
{
	return enemyField->CheckIsAllFired();
}

Field* Player::GetPlayerField() const
{return playerField;}

void Player::SetEnemyField(Field* enemy)
{
	enemyField = new Field(*enemy);
	enemyField->SetIsPlayerField(false);
}