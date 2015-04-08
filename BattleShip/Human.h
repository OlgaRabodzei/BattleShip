#pragma once
#include "player.h"
class Human :
	public Player
{
	void CreateShips();
	void ManuallyPlacing();
public:
	Human(void);
	~Human(void);
	void Fire();
	//Field GetPlayerField() const;
	//void SetEnemyField(Field);

	////Востановление доступа
	//Player::ShowFields;
	//Player::IsWinner;
	//Player::GetPlayerField;

};

