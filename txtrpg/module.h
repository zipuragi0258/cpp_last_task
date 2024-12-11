#pragma once
#include "Player.h"
#include "Monster.h"

void change_state(State state);

void screen_reload();

string get_answer(Gamelog gamelog);

void fighting(int stageLV, Player& player, string answer, Gamelog& gamelog);

void Monster_attack(Player& player, Monster& monster, Gamelog& gamelog);

void Player_attack(Monster& monster, Player& player, Gamelog& gamelog);