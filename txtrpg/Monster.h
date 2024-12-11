#pragma once
#include "Creature.h"
class Monster : Creature
{
public:
	Monster(string name, int hp, int strength)
	{
		Creature::setName(name);
		Creature::setHp(hp);
		Creature::setStrength(strength);
	}
	~Monster(){}

	string getName() { return Creature::getName(); }
	int getLevel() { return Creature::getLevel(); }
	int getHp() { return Creature::getHp(); }
	int getStrength() { return Creature::getStrength(); }
	void setName(string name) { Creature::setName(name); }
	void setHp(int hp) { Creature::setHp(hp); }
	void setStrength(int strength) { Creature::setStrength(strength); }

	
};

