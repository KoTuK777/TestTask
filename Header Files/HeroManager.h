#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Hero.h"

using namespace std;

class HeroManager
{
public:
	vector<Hero> heroes;

	void createHeroes(int n) {
		vector<string> names = {
			"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake"
		};
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; i++) {
			int idx = rand() % names.size();
			int hp = rand() % 100 + 1;
			int damage = rand() % 10 + 1;
			int speed = rand() % 5 + 1;
			Hero hero = Hero(names[idx], hp, damage, speed);
			heroes.push_back(hero);
		}
	}

	void ListOfHeroes() {
		cout << "================================================" << endl << endl;
		for (size_t i = 0; i < heroes.size(); i++) {
			cout << "Name: " << heroes[i].getName()
				<< "\tHP: " << heroes[i].getHP()
				<< "\tDamage: " << heroes[i].getDamage()
				<< "\tSpeed: " << heroes[i].getSpeed()
				<< endl << endl
				<< "================================================"
				<< endl << endl;
		}
	}

	Hero GetHeroByName(string name) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) {
				cout << "Name: " << heroes[i].getName()
					<< "\tHP: " << heroes[i].getHP()
					<< "\tDamage: " << heroes[i].getDamage()
					<< "\tSpeed: " << heroes[i].getSpeed()
					<< endl << endl;
				return heroes[i];
			}
		}
		cout << "There is no hero with this name!" << endl;
	}

	int AddHero(string name, int hp, int damage, int speed) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) {
				cout << "This name is already exist!" << endl;
				return 0;
			}
		}
		Hero hero = Hero(name, hp, damage, speed);
		heroes.push_back(hero);
	}

	void RemovePlayer(string name) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) heroes.erase(heroes.begin() + i);
			break;
		}
	}
};

