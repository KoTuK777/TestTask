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

template <typename T>
void randVector(vector<T>& vec) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < vec.size(); i++) {
		swap(vec[i], vec[rand() % vec.size()]);
	}
}

void createPlayers(vector<Player>& arr, int n) {
	string names[12] = { "Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake" };
	for (int i = 0; i < n; i++) {
		Player player = Player(names[i], 1000, i + 1);
		arr.push_back(player);
	}
}

void createHeroes(vector<Hero>& arr, int n) {
	vector<string> names = { "Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake" };
	randVector(names);
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		int hp = rand() % 100 + 1;
		int damage = rand() % 10 + 1;
		int speed = rand() % 5 + 1;
		Hero hero = Hero(names[i], hp, damage, speed);
		arr.push_back(hero);
	}
}

void createTeamParts(vector<TeamPart>& arr, vector<Player>& players, vector<Hero>& heroes) {
	randVector(players);
	for (int i = 0; i < players.size(); i++)
	{
		TeamPart teamPart = TeamPart(players[i], heroes[i]);
		arr.push_back(teamPart);
	}	
}




int main() {

	vector<Player> players;
	vector<Hero> heroes;
	vector<TeamPart> TeamParts;


	createPlayers(players, 10);
	createHeroes(heroes, 10);
	createTeamParts(TeamParts, players, heroes);

	for (int i = 0; i < 10; i++) {
		cout << "Name: " << TeamParts[i].player.getName()
			<< "\tID: " << TeamParts[i].player.getID()
			<< "\tRank: " << TeamParts[i].player.getRank()
			<< endl << endl;
		cout << "Name: " << TeamParts[i].hero.getName()
			<< "\tHP: " << TeamParts[i].hero.getHP()
			<< "\tDamage: " << TeamParts[i].hero.getDamage()
			<< "\tSpeed: " << TeamParts[i].hero.getSpeed()
			<< endl << endl
			<< "=========================================="
			<< endl << endl;
	}
	cout << endl;
	

	return 0;
	system("pause");
}
