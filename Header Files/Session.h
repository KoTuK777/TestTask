#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

#include "Player.h"
#include "Hero.h"
#include "TeamPart.h"
#include "windows.h"

using namespace std;

template <typename T>
void randVector(vector<T>& vec) {
	srand((unsigned)time(NULL));
	for (size_t i = 0; i < vec.size(); i++) {
		swap(vec[i], vec[rand() % vec.size()]);
	}
}

class Session
{
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
		for (size_t i = 0; i < TeamBlue.size(); i++) {

			int idBlue = TeamBlue[i].player.getID();
			int idRed = TeamRed[i].player.getID();

			for (size_t j = 0; j < players.size(); j++)
			{
				switch (winner) {
				case 1:
					// Blue
					if (players[j].getID() == idBlue) players[j].addRank();
					if (players[j].getID() == idRed) players[j].subRank();
					break;
				case 2:
					// Red
					if (players[j].getID() == idRed) players[j].addRank();
					if (players[j].getID() == idBlue) players[j].subRank();
					break;
				}
			}
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

	bool checkPlayers() {
		int maxBlue = 0, maxRed = 0, minBlue = 999999999, minRed = 999999999;

		for (size_t i = 0; i < TeamBlue.size(); i++)
		{
			if (TeamBlue[i].player.getRank() > maxBlue) maxBlue = TeamBlue[i].player.getRank();
			if (TeamBlue[i].player.getRank() < minBlue) minBlue = TeamBlue[i].player.getRank();

			if (TeamRed[i].player.getRank() > maxRed) maxRed = TeamRed[i].player.getRank();
			if (TeamRed[i].player.getRank() < minRed) minRed = TeamRed[i].player.getRank();
		}

		if (maxBlue - minBlue >= 200 || maxRed - minRed >= 200) return false;

		return true;
	}

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
		for (size_t i = 0; i < 10; i++) {
			if (newHeroes.size() < 10) {
				if (i < 5) {
					TeamPart tp = TeamPart(players[i], newHeroes[i]);
					Lobby.push_back(tp);
				}
				else {
					TeamPart tp = TeamPart(players[i], newHeroes[i - 5]);
					Lobby.push_back(tp);
				}
			}
			else {
				TeamPart tp = TeamPart(players[i], newHeroes[i]);
				Lobby.push_back(tp);
			}
		}

		AddTeamPart();
		//Lim 10 000
		for (int i = 0; (!checkTeams() || !checkPlayers()) && i < 10000; i++)
		{
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

