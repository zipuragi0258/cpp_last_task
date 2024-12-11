#pragma once
#include <iostream>
#include <string>
using namespace std;

class Creature
{
private:
	string name;
	int hp = 100;
	int strength = 5;
	int level = 1;
public:
	string getName() { return name; }
	int getHp() { return hp; }
	int getStrength() { return strength; }
	int getLevel() { return level; }

	void setName(string name) { this->name = name; }
	void setHp(int hp) { this->hp = hp; }
	void setStrength(int strength) { this->strength = strength; }

	void levelUp() { this->level++; }

	void addHp(int hp) { this->hp += hp; }
	void addStrength(int strength) { this->strength += strength; }
};

