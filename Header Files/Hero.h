#pragma once
#include <iostream>

using namespace std;

class Hero
{
private:
	string name;
	int hp;
	int damage;
	int speed;

public:
	Hero() {
		name = "hero";
		hp = 100;
		damage = 5;
		speed = 2;
	}

	Hero(string name, int hp, int damage, int speed) {
		if (name != "") this->name = name;
		if (hp > 0) this->hp = hp;
		if (damage > 0) this->damage = damage;
		if (speed > 0) this->speed = speed;
	}

	string getName() {
		return name;
	}
	int getHP() {
		return hp;
	}
	int getDamage() {
		return damage;
	}
	int getSpeed() {
		return speed;
	}
};
