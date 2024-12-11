#pragma once
#include "Creature.h"

class Player : public Creature
{
private:
    int money = 0;
    int armor = 1;
    int itemDamage = 0;
    int exp = 0;
    int maxExp = 10;

public:
    Player(string name, int hp, int strength)
    {
        Creature::setName(name);     // 부모 클래스의 메서드 호출
        Creature::setHp(hp);
        Creature::setStrength(strength);
    }
    ~Player() {}

    void addMoney(int money) { this->money += money; }
    void addArmor(int armor) { this->armor += armor; }
    void addItemDamage(int damage) { this->itemDamage = damage; }
    void addExp(int exp) { this->exp += exp; }

    string getName() { return Creature::getName(); }
    int getLevel() { return Creature::getLevel(); }
    int getHp() { return Creature::getHp(); }
    int getStrength() { return Creature::getStrength(); }
    int getMoney() { return money; }
    int getArmor() { return armor; }
    int getItemDamage() { return itemDamage; }
    int getExp() { return exp; }
    int getMaxExp() { return maxExp; }

    void levelUp()
    {
        Creature::levelUp();
        Creature::addHp(10);
        Creature::addStrength(5);

        this->exp = 0;
        this->maxExp += 10;
    }

    void setMaxExp(int Exp) { this->maxExp = Exp; }
    void setName(string name) { Creature::setName(name); }
    void setHp(int hp) { Creature::setHp(hp); }
    void setStrength(int strength) { Creature::setStrength(strength); }
};
