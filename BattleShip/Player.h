#pragma once
#include "Field.h"
class Player
{
protected:
	Field *playerField;
	Field *enemyField;
public:
	Player(void);
	virtual ~Player(void);
	virtual void Fire() = 0;
	void ShowFields();
	bool IsWinner();
	Field* GetPlayerField() const;
	void SetEnemyField(Field*);

};

