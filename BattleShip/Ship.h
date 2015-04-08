#pragma once
class Ship
{
	int type;
	bool isDead;
	int hits;
	
public:
	Ship(void);
	~Ship(void);
	bool GetIsDead() const;
	void SetIsDead(bool);
	int GetType() const;
	void SetType(int);
	void AddHit();
};

