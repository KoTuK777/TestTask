#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <conio.h>
#include <string>
#include "string.h"
#include <vector>

using namespace std;

template <typename T>
void randVector(vector<T>& vec) {
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < vec.size(); i++) {
		swap(vec[i], vec[rand() % vec.size()]);
	}
}


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

class PlayerManager {
public:
	vector<Player> players;
	//Test
	/*void sortById() {
		for (int i = 0; i < players.size() - 1; i++) {
			for (int j = 0; j < players.size() - i - 1; j++) {
				if (players[i].getID() > players[i + 1].getID()) swap(players[i], players[i + 1]);
			}
		}
	}*/

	void generatePlayers(int n) {
		vector<string> names = { 
			"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake"
		};
		randVector(names);
		for (int i = 0; i < n; i++) {
			Player player = Player(names[i], 1000, i + 1);
			players.push_back(player);
		}
	}

	void ListOfPlayers() {
		cout << "==================================" << endl << endl;
		for (size_t i = 0; i < players.size(); i++) {
			cout << "Name: " << players[i].getName()
				 << "\tID: " << players[i].getID()
				 << "\tRank: " << players[i].getRank()
				 << endl << endl 
				 << "=================================="
				 << endl << endl;
		}
	}

	Player GetPlayerByName(string name) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getName() == name) {
				//Test
				cout << "Name: " << players[i].getName()
					<< "\tID: " << players[i].getID()
					<< "\tRank: " << players[i].getRank()
					<< endl << endl;
				//End test
				return players[i];
			}
			else continue;
		}
		//???
		cout << "There is no player with this name!" << endl;
	}

	Player GetPlayerById(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getID() == id) {
				//Test
				cout << "Name: " << players[i].getName()
					<< "\tID: " << players[i].getID()
					<< "\tRank: " << players[i].getRank()
					<< endl << endl;
				//End test
				return players[i];
			}
			else continue;
		}
		//???
		cout << "There is no player with this id!" << endl;
	}

	void AddPlayer(string name) {
		int id = players[players.size() - 1].getID() + 1;
		Player player = Player(name, 1000, id);
		players.push_back(player);
	}

	void RemovePlayer(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if(players[i].getID() == id) players.erase(players.begin() + i);
			break;
		}
	}
};

class HeroManager {
public:
	vector<Hero> heroes;

	void createHeroes(int n) {
		vector<string> names = { 
			"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake"
		};
		randVector(names);
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; i++) {
			int hp = rand() % 100 + 1;
			int damage = rand() % 10 + 1;
			int speed = rand() % 5 + 1;
			Hero hero = Hero(names[i], hp, damage, speed);
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
				//Test
				cout << "Name: " << heroes[i].getName()
					<< "\tHP: " << heroes[i].getHP()
					<< "\tDamage: " << heroes[i].getDamage()
					<< "\tSpeed: " << heroes[i].getSpeed()
					<< endl << endl;
				//End test
				return heroes[i];
			}
			else continue;
		}
		//???
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

class TeamPart {
public:
	Player player;
	Hero hero;

	TeamPart() {}
	TeamPart(const Player& player, const Hero& hero) {
		this->player = player;
		this->hero = hero;
	}
};


class Session {
	vector<TeamPart> Lobby;
	vector<TeamPart> TeamRed;
	vector<TeamPart> TeamBlue;
	vector<Hero> newHeroes;
	/*int StartTime;*///???
	string Winner; //???

public:
	//Init
	Session(vector<Player>& players, vector<Hero>& heroes) {
		// Copy heroes to the new array
		for (size_t i = 0; i < heroes.size(); i++) {
			newHeroes.push_back(heroes[i]);
		}

		randVector(newHeroes);

		//Add players and heroes to the Lobby
		for (size_t i = 0; i < players.size(); i++) {
			TeamPart tp = TeamPart(players[i], newHeroes[i]);
			Lobby.push_back(tp);
		}

		randVector(Lobby);

		//Add TeamPart to the teams
		for (size_t i = 0; i < Lobby.size(); i++) {
			if (i < 5) {
				TeamBlue.push_back(Lobby[i]);
			}
			else {
				TeamRed.push_back(Lobby[i]);
			}
		}
	}

	~Session() {
		newHeroes.clear();
		TeamRed.clear();
		TeamBlue.clear();
		Lobby.clear();
	}
	//Test
	/*void showRed() {
		for (int i = 0; i < TeamRed.size(); i++)
		{
			cout << TeamRed[i].player.getName() << endl;
			cout << TeamRed[i].hero.getName() << endl << endl;
		}
	}*/

	void getWinner() {
		int hpBlue = 0, hpRed = 0, damageBlue = 0, damageRed = 0;
		for (size_t i = 0; i < TeamBlue.size(); i++) {
			hpBlue += TeamBlue[i].hero.getHP();
			damageBlue += TeamBlue[i].hero.getDamage();
		}
		for (size_t i = 0; i < TeamRed.size(); i++) {
			hpRed += TeamRed[i].hero.getHP();
			damageRed += TeamRed[i].hero.getDamage();
		}
		

		if (hpBlue - damageRed > hpRed - damageBlue) {
			Winner = "Blue";
		}
		else if (hpBlue - damageRed == hpRed - damageBlue) {
			Winner = "Tie";
		}
		else {
			Winner = "Red";
		}
	}

	void AnnounceTheWinner() {
		cout << Winner << " won this game" << endl;
	}

};

int main() {

	PlayerManager pm;
	HeroManager hm;
	pm.generatePlayers(10);
	hm.createHeroes(10);


	Session session(pm.players, hm.heroes);

	session.getWinner();
	session.AnnounceTheWinner();

	return 0;
	system("pause");
}
