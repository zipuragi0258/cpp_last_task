#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#include "state.h"
#include "Gamelog.h"
#include "module.h"
#include "Player.h"


void print_start_screen()
{
	system("cls");
	cout << "\n\n\n\n" << "                       JunHa's\n" << "                         Adventure\n\n\n\n" << "============================================================\n";
}

void print_select_player_screen()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "                 Knight          Mage\n\n\n\n\n";
	cout << "============================================================\n"; 
}

void print_town_screen()
{
	cout << "\n                        get reward\n\n\n";
	cout << " go shop               『town』               go field\n\n\n\n\n";
	cout << "============================================================\n";
}

void print_shop_screen()
{
	cout << "\n                       『shop』\n\n";
	cout << "  짱쎈칼  |  튼튼한 갑옷  |  마법사의 반지 |  생명의 토템\n";
	cout << " (전사용) |     (공용)    |   (마법사용)   |     (공용)  \n";
	cout << "  st +20  |    am +%20    |     st +20     |  max hp +100\n";
	cout << "   20G    |      50G      |      20G       |      100G   \n\n  go town             buy item\n";
	cout << "============================================================\n";
}

void print_select_level_screen()
{
	cout << "\n\n\n\n";
	cout << "                     select stage\n\n\n\n\n";
	cout << "============================================================\n";
}

void print_field_screen()
{
	cout << "\n\n\n\n";
	cout << "  go town                                     select stage\n\n\n\n\n";
	cout << "============================================================\n";
}


void print_player_dead()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "        player dead\n\n\n\n\n";
	cout << "============================================================\n";
}

void print_stage_clear()
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "                       stage clear\n\n\n\n\n";
	cout << "============================================================\n";
}

void print_string(string str)
{
	system("cls");
	cout << "\n\n\n\n";
	cout << "        " << str << "\n\n\n\n";
	cout << "============================================================\n";
}