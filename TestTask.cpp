#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "windows.h"
#include <conio.h>
#include <string>
#include "string.h"
#include <vector>  
#include <math.h>
#include <fstream>

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
	int rank;
	int id;

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
		id = 0;
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
		}
		//???
		/*cout << "There is no player with this id!" << endl;*/
	}

	void AddPlayer(string name) {
		int id = players[players.size() - 1].getID() + 1;
		Player player = Player(name, 1000, id);
		players.push_back(player);
	}

	void RemovePlayer(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getID() == id) players.erase(players.begin() + i);
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
	time_t StartTime = 0;

	int winner = -1;

	void chooseWinner() {
		int hpBlue = 0, hpRed = 0, damageBlue = 0, damageRed = 0;
		//Calculate hp and damage
		for (size_t i = 0; i < TeamBlue.size(); i++) {
			hpBlue += TeamBlue[i].hero.getHP();
			damageBlue += TeamBlue[i].hero.getDamage();
		}
		for (size_t i = 0; i < TeamRed.size(); i++) {
			hpRed += TeamRed[i].hero.getHP();
			damageRed += TeamRed[i].hero.getDamage();
		}

		if (hpBlue - damageRed > hpRed - damageBlue) {
			winner = 1;//Blue
		}
		else if (hpBlue - damageRed == hpRed - damageBlue) {
			winner = 0;//Tie
		}
		else {
			winner = 2;//Red
		}
	}

	void AnnounceTheWinner() {
		if (winner > 0) {
			cout << arr[winner] << " won this game" << endl;
		}
		else {
			cout << arr[winner] << endl;
		}
	}

	void ChangeRank(vector<Player>& players) {
		//Test with bags
		switch (winner) {
		case 1:
			for (size_t i = 0; i < TeamBlue.size(); i++) {
				int idWinner = TeamBlue[i].player.getID();
				int idLoser = TeamRed[i].player.getID() - 1;
				for (size_t i = 0; i < players.size(); i++) {
					if (players[i].getID() == idWinner) {
						players[i].addRank();
					}
					if (players[i].getID() == idLoser) {
						players[i].subRank();
					}
				}
			}
			break;
		case 2:
			for (size_t i = 0; i < TeamRed.size(); i++) {
				int idWinner = TeamRed[i].player.getID();
				int idLoser = TeamBlue[i].player.getID() - 1;
				for (size_t i = 0; i < players.size(); i++) {
					if (players[i].getID() == idWinner) {
						players[i].addRank();
					}
					if (players[i].getID() == idLoser) {
						players[i].subRank();
					}
				}
			}
			break;
		}
	}

	void AddTeamPart() {
		for (size_t i = 0; i < Lobby.size(); i++) {
			if (i < 5) {
				TeamBlue.push_back(Lobby[i]);
			}
			else {
				TeamRed.push_back(Lobby[i]);
			}
		}
	}

	bool checkTeams() {
		int mmrRed = 0, mmrBlue = 0;
		for (size_t i = 0; i < TeamRed.size(); i++) {
			mmrRed += TeamRed[i].player.getRank();
			mmrBlue += TeamBlue[i].player.getRank();
		}
		if (fabs(mmrBlue - mmrRed) >= 100)	return false;
		return true;
	}


	//Test
	/*bool checkPlayers() {
		int maxBlue = 0, maxRed = 0, minBlue = 999999999, minRed = 999999999;

		for (size_t i = 0; i < TeamBlue.size(); i++)
		{
			if (TeamBlue[i].player.getRank() > maxBlue) maxBlue = TeamBlue[i].player.getRank();
			if (TeamBlue[i].player.getRank() < minBlue) minBlue = TeamBlue[i].player.getRank();

			if (TeamRed[i].player.getRank() > maxRed) maxRed = TeamRed[i].player.getRank();
			if (TeamRed[i].player.getRank() < minRed) minRed = TeamRed[i].player.getRank();
		}

		//Test
		cout << "MaxBlue: " << maxBlue << endl;
		cout << "minBlue: " << minBlue << endl;

		cout << "maxRed: " << maxRed << endl;		
		cout << "minRed: " << minRed << endl << endl;
		if (maxBlue - minBlue <= 200 || maxRed - minRed <= 200) return false;
		
		return true;
	}*/

	

public:
	string arr[3] = { "Tie", "Blue", "Red" };
	//Init

	Session(vector<Player>& players, vector<Hero>& heroes) {
		// Copy heroes to the new array
		for (size_t i = 0; i < heroes.size(); i++) {
			newHeroes.push_back(heroes[i]);
		}

		randVector(players);
		randVector(newHeroes);

		//Add players and heroes to the Lobby
		for (size_t i = 0; i < players.size(); i++) {
			TeamPart tp = TeamPart(players[i], newHeroes[i]);
			Lobby.push_back(tp);
		}

		AddTeamPart();
		//Need test!
		while (!checkTeams()) {
			randVector(Lobby);
			TeamBlue.clear();
			TeamRed.clear();
			AddTeamPart();
		}

		//For randomizing
		Sleep(1000);
	}

	~Session() {
		newHeroes.clear();
		TeamRed.clear();
		TeamBlue.clear();
		Lobby.clear();
	}
	//Test
	void showTeamRed() {
		cout << endl
			<< "                  Team Red" << endl << endl
			<< "================================================" << endl << endl;
		for (size_t i = 0; i < TeamRed.size(); i++)
		{
			//Show player info
			cout << "Name: " << TeamRed[i].player.getName()
				<< "\tID: " << TeamRed[i].player.getID()
				<< "\tRank: " << TeamRed[i].player.getRank()
				<< endl;
			//Shwow hero info
			cout << "Name: " << TeamRed[i].hero.getName()
				<< "\tHP: " << TeamRed[i].hero.getHP()
				<< "\tDamage: " << TeamRed[i].hero.getDamage()
				<< "\tSpeed: " << TeamRed[i].hero.getSpeed()
				<< endl
				<< (i == TeamRed.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		cout << "================================================" << endl << endl;
	}

	void showTeamBlue() {
		cout << endl
			<< "                  Team Blue" << endl << endl
			<< "================================================" << endl << endl;
		for (size_t i = 0; i < TeamBlue.size(); i++)
		{
			//Show player info
			cout << "Name: " << TeamBlue[i].player.getName()
				<< "\tID: " << TeamBlue[i].player.getID()
				<< "\tRank: " << TeamBlue[i].player.getRank()
				<< endl;
			//Shwow hero info
			cout << "Name: " << TeamBlue[i].hero.getName()
				<< "\tHP: " << TeamBlue[i].hero.getHP()
				<< "\tDamage: " << TeamBlue[i].hero.getDamage()
				<< "\tSpeed: " << TeamBlue[i].hero.getSpeed()
				<< endl
				<< (i == TeamBlue.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		cout << "================================================" << endl << endl;
	}

	void gameStart(vector<Player>& players) {
		StartTime = time(0);
		chooseWinner();
		AnnounceTheWinner();
		ChangeRank(players);
	}

	time_t getTime() {
		return StartTime;
	}

	void showTime() {
		tm* ltm = localtime(&StartTime);
		cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\t"
		     << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
	}

	int getWinner() {
		return winner;
	}

	void saveLog() {
		ofstream fout;
		fout.open("log.txt", ofstream::app);

		fout << endl << endl << "New Game" << endl << endl;

		//Save time
		tm* ltm = localtime(&StartTime);
		fout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\t"
			 << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

		//Save winner
		int winner = getWinner();
		fout << arr[winner] << " won" << endl;

		//Save team red
		fout << endl
			<< "                  Team Red" << endl << endl
			<< "================================================" << endl << endl;
		for (size_t i = 0; i < TeamRed.size(); i++)
		{
			//Show player info
			fout << "Name: " << TeamRed[i].player.getName()
				<< "\tID: " << TeamRed[i].player.getID()
				<< "\tRank: " << TeamRed[i].player.getRank()
				<< endl;
			//Shwow hero info
			fout << "Name: " << TeamRed[i].hero.getName()
				<< "\tHP: " << TeamRed[i].hero.getHP()
				<< "\tDamage: " << TeamRed[i].hero.getDamage()
				<< "\tSpeed: " << TeamRed[i].hero.getSpeed()
				<< endl
				<< (i == TeamRed.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		fout << "================================================" << endl << endl;

		//Save team blue
		fout << endl
			<< "                  Team Blue" << endl << endl
			<< "================================================" << endl << endl;
		for (size_t i = 0; i < TeamBlue.size(); i++)
		{
			//Show player info
			fout << "Name: " << TeamBlue[i].player.getName()
				<< "\tID: " << TeamBlue[i].player.getID()
				<< "\tRank: " << TeamBlue[i].player.getRank()
				<< endl;
			//Shwow hero info
			fout << "Name: " << TeamBlue[i].hero.getName()
				<< "\tHP: " << TeamBlue[i].hero.getHP()
				<< "\tDamage: " << TeamBlue[i].hero.getDamage()
				<< "\tSpeed: " << TeamBlue[i].hero.getSpeed()
				<< endl
				<< (i == TeamBlue.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		fout << "================================================" << endl << endl;

		fout.close();
	}
};

class SessionManager {
	vector<Session> sessions;
	time_t time = 0;

public:
	SessionManager() {}

	void ListOfSessions() {
		for (size_t i = 0; i < sessions.size(); i++) {
			cout << i + 1 << ". ";
			sessions[i].showTime();
			int winner = sessions[i].getWinner();
			cout << sessions[i].arr[winner] << " won" << endl;
		}
	}

	void PerformGameSession(vector<Player>& players, vector<Hero>& heroes, int num) {
		for (int i = 0; i < num; i++) {
			Session session(players, heroes);
			session.gameStart(players);
			session.saveLog();
			session.showTime();
			session.showTeamBlue();
			session.showTeamRed();
			sessions.push_back(session);
		}
	}
};

int main() {

	PlayerManager pm;
	HeroManager hm;
	SessionManager sm;
	pm.generatePlayers(10);
	hm.createHeroes(10);
	pm.ListOfPlayers();

	sm.PerformGameSession(pm.players, hm.heroes, 5);
	sm.ListOfSessions();

	pm.ListOfPlayers();

	//Create menu

	system("pause");
	return 0;
}
