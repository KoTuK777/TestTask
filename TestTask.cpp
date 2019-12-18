#include <iostream>
#include <string>
#include <ctime>
#include "string.h"

//Classes
#include "PlayerManager.h"
#include "HeroManager.h"
#include "SessionManager.h"

using namespace std;

int main() {
	PlayerManager pm;
	HeroManager hm;
	SessionManager sm;


	pm.generatePlayers(20);
	hm.createHeroes(10);

	pm.ListOfPlayers();

	sm.PerformGameSession(pm.players, hm.heroes, 10);
	sm.ListOfSessions();

	pm.ListOfPlayers();

	system("pause");
	return 0;
}
