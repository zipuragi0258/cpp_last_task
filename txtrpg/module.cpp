#include <iostream>
#include <string>
#include <vector>

#include "state.h"
#include "module.h"
#include "screen_printing.h"
#include "Gamelog.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

void change_state(State state)
{
	nowPlace = state;
}

void screen_reload()
{
	system("cls");
	if (nowPlace == BEFORE_GAME) { print_start_screen(); }
	else if (nowPlace == INIT_GAME) { print_select_player_screen(); }
	else if (nowPlace == TOWN) { print_town_screen(); }
	else if (nowPlace == SHOP) { print_shop_screen(); }
	else if (nowPlace == FIELD) { print_field_screen(); }
	else if (nowPlace == SELECT_STAGE) { print_select_level_screen(); }
}

string get_answer(Gamelog gamelog)
{
	string answer;

	while (true)
	{
		getline(cin, answer);

		if (nowPlace == INIT_GAME)
		{
			if (answer == "knight" || answer == "mage")
			{
				gamelog.add_log("(you) " + answer);
				return answer;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				screen_reload();
				gamelog.print_log();
			}
		}
		else if (nowPlace == TOWN)
		{
			if (answer == "go shop" || answer == "go field" || answer == "get reward")
			{
				gamelog.add_log("(you) " + answer);
				return answer;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				screen_reload();
				gamelog.print_log();
			}
		}
		else if (nowPlace == SHOP)
		{
			if (answer == "buy item" || answer == "sell item" || answer == "go town")
			{
				gamelog.add_log("(you) " + answer);
				return answer;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				screen_reload();
				gamelog.print_log();
			}
		}
		else if (nowPlace == FIELD)
		{
			if (answer == "select stage" || answer == "go town")
			{
				gamelog.add_log("(you) " + answer);
				return answer;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				screen_reload();
				gamelog.print_log();
			}
		}
		else if (nowPlace == ON_FIGHTING)
		{
			if (answer == "attack" || answer == "shield" || answer == "heal" || answer == "run away")
			{
				gamelog.add_log("(you) " + answer);
				return answer;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				screen_reload();
				gamelog.print_log();
			}
		}
	}
}

void fighting(int stageLV, Player& player, string answer, Gamelog& gamelog)
{
	Player saveP = player;
	Monster m1("monster lv."+to_string(stageLV), 5 + 10*stageLV, 5*stageLV);

	system("cls");
	cout << "\n\n\n\n";
	cout << "            " << player.getName() << "               " << m1.getName() << "\n";
	cout << "            hp " << player.getHp() << "               " << m1.getHp() << "\n\n\n       attack | shield | heal | run away\n";
	cout << "============================================================\n";
	gamelog.print_log();

	while (true)
	{

		while(true)
		{
			getline(cin, answer);

			if (answer == "attack" || answer == "shield" || answer == "heal" || answer == "run away")
			{
				gamelog.add_log("(you) " + answer);
				break;
			}
			else
			{
				gamelog.add_log("(A) You enter wrong answer!");
				system("cls");
				cout << "\n\n\n\n";
				cout << "        " << player.getName() << "            " << m1.getName() << "\n";
				cout << "        hp " << player.getHp() << "            " << m1.getHp() << "\n\n\n       attack | shield | heal | run away\n";
				cout << "============================================================\n";
				gamelog.print_log();
			}
		}

		if (answer == "attack")
		{
			Player_attack(m1, player, gamelog);
		}
		else if (answer == "shield")
		{

		}
		else if (answer == "heal")
		{
			player.setHp(player.getHp() + 10*player.getLevel());
			gamelog.add_log("(A) 당신은 " + to_string(10 * player.getLevel()) + "만큼 회복했습니다.");
		}
		else if (answer == "run away")
		{
			gamelog.add_log("(A) 당신은 도망갔습니다.");
			player = saveP;
			break;
		}

		if (m1.getHp() <= 0)
		{
			gamelog.add_log("(A) 몬스터를 처치했습니다.");
			break;
		}

		if (answer == "shield")
		{
			gamelog.add_log("(A) 공격을 막았습니다.");
		}
		else
		{
			Monster_attack(player, m1, gamelog);
		}

		if (player.getHp() <= 0)
		{
			gamelog.add_log("(A) 당신은 죽었습니다.");
			exit(0);
		}

		system("cls");
		cout << "\n\n\n\n";
		cout << "            " << player.getName() << "               " << m1.getName() << "\n";
		cout << "            hp " << player.getHp() << "               " << m1.getHp() << "\n\n\n  attack | shield | heal | run away\n";
		cout << "============================================================\n";
		gamelog.print_log();
	}
}

void Monster_attack(Player& player, Monster& monster, Gamelog& gamelog)
{
	int damage = monster.getStrength() * (100-player.getArmor()) / 100;
	player.setHp(player.getHp() - damage);
	gamelog.add_log("(A) " + monster.getName() + "(이)가 " + player.getName() + "을(를) " + to_string(damage) + "만큼 공격했습니다.");
}

void Player_attack(Monster& monster, Player& player, Gamelog& gamelog)
{
	int damage = player.getStrength();
	monster.setHp(monster.getHp() - damage);
	gamelog.add_log("(A) " + player.getName() + "(이)가 " + monster.getName() + "을(를) " + to_string(damage) + "만큼 공격했습니다.");
}