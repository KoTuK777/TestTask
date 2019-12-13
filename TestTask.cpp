#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

int idx = 0;

class Player {
private:
	string name;
	int rank = 0;
	int id = 0;

public:
	void setName(string newName) {
		if(name != "") name = newName;
	}

	void addRank() {
		rank += 25;
	}

	void subRank() {
		if (rank >= 25)	rank -= 25;
	}

	Player() {
		name = "unknown";
		id = ++idx;
	}

	Player(string name, int rank) {
		setName(name);
		this->rank = rank;
		this->id = ++idx;
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
	Hero(string name, int hp, int damage, int speed) {
		if (name != "") this->name = name;
		if (hp > 0) this->hp = hp;
		if (damage > 0) this->damage = damage;
		if (speed > 0) this->speed = speed;
	}

	string getName() {
		cout << name << endl;
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

	/*vector<void> players;
	Player player("Tom");

	players[0] = player;

	cout << players[0] << endl;*/
	const int SIZE = 5;

	Player player1("Tom", 1000);
	Player player2("Jame", 1000);
	Player player3("Stive", 1000);
	Player player4("John", 1000);
	Player player5("Rick", 1000);


	Player arr[SIZE];
	arr[0] = player1;
	arr[1] = player2;
	arr[2] = player3;




	cout << arr[0].getID() << endl;
	cout << arr[1].getID() << endl;
	cout << arr[2].getID() << endl;
	cout << player1.getID() << endl;
	cout << player2.getID() << endl;
	cout << player3.getID() << endl;
	/*cout << arr[0].getName() << endl;*/

	

	return 0;
	system("pause");
}
