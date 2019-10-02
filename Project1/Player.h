#pragma once
#include <string>

class Player
{
public:
	//Constructors
	Player();
	Player(std::string pName, std::string pTeam);
	~Player();

	//Methods
	std::string getName();
	std::string getTeam();
	int getPoints();
	int getConstructorPoints();
	void addPoints(int pt);
	void addConstructors(int pkt);
	void setDiff(int p);
	int getDiff();
	void addWins();
	int getWins();

private:
	//Attributes
	int wmPoints = 0, constructorsPoints = 0, diff = 0, wins = 0, fastestLaps = 0;
	std::string name;
	std::string team;
};
