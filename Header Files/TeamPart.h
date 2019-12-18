#pragma once
#include <iostream>
#include "Player.h"
#include "Hero.h"

using namespace std;

class TeamPart
{
public:
	Player player;
	Hero hero;

	TeamPart(const Player& player, const Hero& hero) {
		this->player = player;
		this->hero = hero;
	}
};

