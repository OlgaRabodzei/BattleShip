#pragma once
#include <ctime>
#include "player.h"

class Computer :
	public Player
{
public:
	Computer(void);
	~Computer(void);
	void Fire();
	//������������� �������
	/*Player::ShowFields;
	Player::IsWinner;
	Player::GetPlayerField;*/
};

