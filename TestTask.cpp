#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <conio.h>
#include <string>
#include "string.h"
#include <vector>

using namespace std;

class Player {
private:
	string name;
	int rank = 0;
	int id = 0;

public:
	void setName(string name) {
		this->name = name;
	}

	void addRank() {
		rank += 25;
	}

	void subRank() {
		if (rank >= 25)	rank -= 25;
	}

	Player() {
		name = "unknown";
		rank = 1000;
		id = rank % 1000;
	}

	Player(string name, int rank, int id) {
		this->name = name;
		this->rank = rank;
		this->id = id;
	}

	string getName() {

		return name;
	}
	int getRank() {
		return rank;
	}
	int getID() {
		return id;
	}

};

class Hero {
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

class TeamPart {
private:
	

public:
	Player player;
	Hero hero;

	TeamPart() {
		this->player.setName("unknown");
	}
	TeamPart(const Player& player, const Hero& hero) {
		this->player = player;
		this->hero = hero;
	}
};

class Session {
	TeamPart teamRed[5];
	TeamPart teamBlue[5];

	/*void setRed(TeamPart* arr[]) {
		for (int i = 0; i < 5; i++) {
			teamBlue[i] = arr[i];
		}
	}*/





};

void createPlayers(int n) {
	string names[12] = {"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake"};
	vector<Player*> Players;
	for (int i = 0; i < n; i++) {
		Player* player = new Player(names[i], 1000, i+1);
		Players.push_back(player);
	}
	//Test
	for (int i = 0; i < n; i++) {
		cout << "Name: " << Players[i]->getName() 
			 << "\tID: " << Players[i]->getID() 
			 << "\tRank: " << Players[i]->getRank() 
			 << endl;
	}
}

void createHeroes(int n) {
	string names[12] = { "Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake" };
	vector<Hero*> Heroes;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int hp = rand() % 100 + 1;
		int damage = rand() % 10 + 1;
		int speed = rand() % 5 + 1;
		Hero* hero = new Hero(names[i], hp, damage, speed);
		Heroes.push_back(hero);
	}
	//Test
	for (int i = 0; i < n; i++) {
		cout << "Name: " << Heroes[i]->getName() 
			 << "\tHP: " << Heroes[i]->getHP() 
			 << "\tDamage: " << Heroes[i]->getDamage() 
			 << "\tSpeed: " << Heroes[i]->getSpeed() 
			 << endl;
	}
}



int main() {

	createPlayers(10);
	cout << endl;
	createHeroes(10);
	
	return 0;
	system("pause");
}
