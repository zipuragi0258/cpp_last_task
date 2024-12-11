#include <iostream>
#include <string>
#include <vector>
#include "Gamelog.h"
#include "Player.h"

using namespace std;


enum State
{
	BEFORE_GAME,
	INIT_GAME,
	TOWN,
	SHOP,
	FIELD,
	SELECT_STAGE,
	ON_FIGHTING
};

static State nowPlace;
