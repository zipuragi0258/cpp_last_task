#pragma once
#include <string>
#include <iostream>
using namespace std;

class Gamelog
{
public:
	string log[4];

	Gamelog(string one, string two, string three, string four)
	{
		log[0] = one;
		log[1] = two;
		log[2] = three;
		log[3] = four;
	}

	void add_log(string message)
	{
		log[0] = log[1];
		log[1] = log[2];
		log[2] = log[3];
		log[3] = message;
	}

	void print_log()
	{
		for (int i = 0; i < 4; i++)
		{
			cout << log[i] << "\n";
		}
	}
};

