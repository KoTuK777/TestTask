#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

class Player {
private:
	string name;
	int rank = 0;
	int id = 0;

public:
	void setName(string newName) {
		name = newName;
	}

	void setID() {
		srand((unsigned)time(NULL));
		if (id != 0) id = rand() % 100000 + 1;
	}

	void addRank() {
		rank += 25;
	}

	void subRank() {
		if(rank >= 25)	rank -= 25;
	}

	Player(string name) {
		setName(name);
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
	string name = "";
	int hp = -1;
	int damage = -1;
	int speed = -1;

public:
	Hero(string n, int h, int d, int s) {
		if (n != "") name = n;
		if (h > 0) hp = h;
		if (d > 0) damage = d;
		if (s > 0) speed = s;
	}
	/*void setName(string newName) {
		if (name == "" && newName != "") name = newName;
	}
	void setHp(int newHp) {
		if(hp == -1 && newHp > 0) hp = newHp;
	}
	void setDamage(int newDamage) {
		if (damage == -1 && newDamage > 0) damage = newDamage;
	}
	void setSpeed(int newSpeed) {
		if (speed == -1 && newSpeed > 0) speed = newSpeed;
	}*/

	string getName() {
		return name;
	}
	int getHP(){
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
	int playerId;
	string heroName;

public:
	void setPlayer(int player) {
		playerId = player;
	}
	void setHero(string hero) {
		heroName = hero;

	}
};

class Session {
};





int main() {

	vector<void> players;
	Player player("Tom");

	players[0] = player;

	cout << players[0] << endl;


	return 0;
	system("pause");
}