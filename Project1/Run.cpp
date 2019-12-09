#pragma once
#include "Run.h"

//outsourced Main
void run() {
    //for emptying constructors list
	int test = 0;

	//welcome
	std::cout << "WILLKOMMEN BEIM F1 2014 PUNKT-MANAGEMENT-SYSTEM" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	//init Players
	std::string playerName, teamName; int num;
	//Player1 testinglol
	std::cout << "Name Spieler 1: "; std::cin >> playerName;
	std::cout << "Team Spieler 1 (1-Ferrari, 2-McLaren, 3-RedBull, 4-Mercedes): "; std::cin >> num;
	teamName = teamSwitch(num);
	Player sEins(playerName, teamName);
	//Player2
	std::cout << "Name Spieler 2: "; std::cin >> playerName;
	std::cout << "Team Spieler 2 (1-Ferrari, 2-McLaren, 3-RedBull, 4-Mercedes): "; std::cin >> num;
	teamName = teamSwitch(num);
	Player sZwei(playerName, teamName);

	//init CPU-Drivers
	Player hamilton("Hamilton", "Mercedes");	Player rosberg("Rosberg", "Mercedes");		Player magnussen("Magnussen", "McLaren");
	Player vettel("Vettel", "RedBull");			Player ricciardo("Ricciardo", "RedBull");	Player alonso("Alonso", "Ferrari");
			
	//list for sorting the championship
	std::list<Player> championshipList;

	//loop through Calendar
	for (int i = 1; i < 20; i++) {
		std::string circName = circNames(i);
		//header
		std::cout << "\n\nRENNRESULTAT: " << circName << "(Rennen " << i << " von 19)" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		//calc results
		std::cout << "Platzierung von " << sEins.getName() << ": ";		std::cin >> num; sEins.addPoints(placeTranslator(num));	if (num == 1) { sEins.addWins(); }
		std::cout << "Platzierung von " << sZwei.getName() << ": ";		std::cin >> num; sZwei.addPoints(placeTranslator(num)); if (num == 1) { sZwei.addWins(); }
		std::cout << "Platzierung von " << hamilton.getName() << ": ";	std::cin >> num; hamilton.addPoints(placeTranslator(num)); if (num == 1) { hamilton.addWins(); }
		std::cout << "Platzierung von " << rosberg.getName() << ": ";	std::cin >> num; rosberg.addPoints(placeTranslator(num)); if (num == 1) { rosberg.addWins(); }
		std::cout << "Platzierung von " << alonso.getName() << ": ";	std::cin >> num; alonso.addPoints(placeTranslator(num)); if (num == 1) { alonso.addWins(); }
		std::cout << "Platzierung von " << magnussen.getName() << ": ";	std::cin >> num; magnussen.addPoints(placeTranslator(num)); if (num == 1) { magnussen.addWins(); }
		std::cout << "Platzierung von " << vettel.getName() << ": ";	std::cin >> num; vettel.addPoints(placeTranslator(num)); if (num == 1) { vettel.addWins(); }
		std::cout << "Platzierung von " << ricciardo.getName() << ": ";	std::cin >> num; ricciardo.addPoints(placeTranslator(num)); if (num == 1) { ricciardo.addWins(); }

		//to empty the list, cause otherwise drivers point cannot be updated correctly
		if (test != 0) {for (int j = 1; j < 9; j++) { championshipList.pop_front(); }}	test++;

		//(re)fill the list with updated points
		championshipList.push_back(sEins); championshipList.push_back(sZwei); championshipList.push_back(hamilton); championshipList.push_back(rosberg);
		championshipList.push_back(alonso); championshipList.push_back(magnussen); championshipList.push_back(vettel); championshipList.push_back(ricciardo);

		//sort the list after points, so it can be poped out in order
		championshipList.sort([](Player &f, Player &s) {return f.getPoints() > s.getPoints();});

		//show drivers championship
		std::cout << "\n\nDRIVERS CHAMPIONSHIP NACH " << circName << "(Rennen " << i << " von 19)" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(10) << "FAHRER" << std::setw(10) <<	"TEAM"	<< std::setw(10) <<	"PUNKTE" << std::setw(10) << "DIFF." << std::endl;
		//loop through the sorted list and print current drivers stand
		for (std::list<Player>::iterator it = championshipList.begin(); it != championshipList.end(); it++) {
			//calc difference to leader
			int cmp = championshipList.begin()->getPoints(); it->setDiff(it->getPoints() - cmp);
			std::cout << std::setw(10) << it->getName() << std::setw(10) << it->getTeam() << std::setw(10) << it->getPoints() << std::setw(10) << it->getDiff() << std::endl;
			//calc constructor points
			for (std::list<Player>::iterator zw = std::next(it); zw != championshipList.end(); zw++) {
				if (it->getTeam() == zw->getTeam()) {
					int toAdd = it->getPoints() + zw->getPoints();
					it->addConstructors(toAdd);
				}	
			}
		}

		//sort List for Constructors
		championshipList.sort([](Player &x, Player &y) {return x.getConstructorPoints() > y.getConstructorPoints(); });
		int mercedesCount = 0, ferrariCount = 0, mclarenCount = 0, redbullCount = 0;

		//show constructors championship
		std::cout << "\n\nCONSTRUCTORS CHAMPIONSHIP NACH " << circName << "(Rennen " << i << " von 19)" << std::endl;
		std::cout << "----------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(10) << "TEAM" << std::setw(10) << "PUNKTE" << std::setw(10) << "DIFF." << std::endl;
		for (std::list<Player>::iterator con = championshipList.begin(); con != championshipList.end(); con++) {
			//calc difference to leader
			int dif = championshipList.begin()->getConstructorPoints(); con->setDiff(con->getConstructorPoints() - dif);
			//trick: cause otherwise it will show the help points
			if (con->getTeam() == "Mercedes" && mercedesCount == 0) {
				std::cout << std::setw(10) << con->getTeam() << std::setw(10) << con->getConstructorPoints() << std::setw(10) << con->getDiff() << std::endl;
				mercedesCount++;
			}
			if (con->getTeam() == "McLaren" && mclarenCount == 0) {
				std::cout << std::setw(10) << con->getTeam() << std::setw(10) << con->getConstructorPoints() << std::setw(10) << con->getDiff() << std::endl;
				mclarenCount++;
			}
			if (con->getTeam() == "Ferrari" && ferrariCount == 0) {
				std::cout << std::setw(10) << con->getTeam() << std::setw(10) << con->getConstructorPoints() << std::setw(10) << con->getDiff() << std::endl;
				ferrariCount++;
			}
			if (con->getTeam() == "RedBull" && redbullCount == 0) {
				std::cout << std::setw(10) << con->getTeam() << std::setw(10) << con->getConstructorPoints() << std::setw(10) << con->getDiff() << std::endl;
				redbullCount++;
			}
		}
	}

	//finish congratulation message -> Winner Drivers, Constructors & Fastest Lap
	std::cout << std::setw(10) << "\n\nEND OF SEASON" << std::endl;
	std::cout << "----------------------------------------------------------------------------" << std::endl;

	championshipList.sort([](Player &f, Player &s) {return f.getPoints() > s.getPoints(); });
	Player winner = *championshipList.begin();
	std::cout << "CONGRATULATIONS! " << winner.getName() << " YOU WON THE CHAMPIONSHIP WITH: " << winner.getWins() << " WINS!" << std::endl;

	championshipList.sort([](Player &x, Player &y) {return x.getConstructorPoints() > y.getConstructorPoints(); });
	winner = *championshipList.begin();
	std::cout << "\nCONGRATULATIONS! " << winner.getTeam() << " YOU WON THE CHAMPIONSHIP!\n" << std::endl;

	/*possible extensions:
	-save this session
	-fastest lap
	-season ending matrix
	*/
}