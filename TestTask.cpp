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
		if (name != "") name = newName;
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
	Player player;
	Hero hero;

public:


	TeamPart() {
		this->player.setName("unknown") ;
	}
	TeamPart(const Player &player, const Hero &hero) {
		this->player = player;
		this->hero = player;
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





int main() {


	string names[10] = {
		"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip"
	};
	

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
	Player player6("Philip", 1000);
	Player player7("Luke", 1000);
	Player player8("Diego", 1000);
	Player player9("Eric", 1000);
	Player player10("Fred", 1000);

	Hero hero1();
	Hero hero2();
	Hero hero3();
	Hero hero4();
	Hero hero5();
	Hero hero6();
	Hero hero7();
	Hero hero8();
	Hero hero9();
	Hero hero10();	

	TeamPart teampart1(player1, hero1);
	TeamPart teampart2(Player player2, Hero hero2);
	TeamPart teampart3(Player player3, Hero hero3);
	TeamPart teampart4(Player player4, Hero hero4);
	TeamPart teampart5(Player player5, Hero hero5);
	TeamPart teampart6(Player player6, Hero hero6);
	TeamPart teampart7(Player player7, Hero hero7);
	TeamPart teampart8(Player player8, Hero hero8);
	TeamPart teampart9(Player player9, Hero hero9);
	TeamPart teampart10(Player player10, Hero hero10);

	/*Player arr[SIZE];
	arr[0] = player1;
	arr[1] = player2;
	arr[2] = player3;
	arr[3] = player4;
	arr[4] = player5;*/

	


	/*cout << arr[0].getID() << endl;
	cout << arr[1].getID() << endl;
	cout << arr[2].getID() << endl;
	cout << player1.getID() << endl;
	cout << player2.getID() << endl;
	cout << player3.getID() << endl;*/
	/*cout << arr[0].getName() << endl;*/



	return 0;
	system("pause");
}
