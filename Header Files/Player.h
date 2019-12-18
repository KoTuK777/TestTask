#pragma once
#include <iostream>
#include <string>

using namespace std;

class Player
{
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
