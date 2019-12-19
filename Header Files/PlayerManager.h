#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Player.h"

using namespace std;

class PlayerManager
{
public:
	vector<Player> players;

	void generatePlayers(int n) {
		vector<string> names = {
			"Tom", "Jame", "Stive", "John", "Rick", "Fred", "Eric", "Diego", "Luke", "Philip", "Oliver", "Jake"
		};
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; i++) {
			int idx = rand() % names.size();
			Player player = Player(names[idx], 1000, i + 1);
			players.push_back(player);
		}
	}

	void sortPlayersById() {
		for (size_t i = 0; i < players.size() - 1; i++)
		{
			for (size_t j = 0; j < players.size() - i - 1; j++)
			{
				if (players[j].getID() > players[j + 1].getID()) swap(players[j], players[j + 1]);
			}
		}
	}

	void ListOfPlayers() {
		sortPlayersById();
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
				return players[i];
			}
		}
	}

	Player GetPlayerById(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getID() == id) {
				return players[i];
			}
		}
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
