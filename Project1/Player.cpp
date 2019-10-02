#pragma once
#include "Player.h"

//default Constructor
Player::Player(){}

//init Constructor
Player::Player(std::string pName, std::string pTeam)
{
	this->name = pName;
	this->team = pTeam;
}

//default Destructor
Player::~Player(){}

//simple Setters/Getters
std::string Player::getName()
{
	return name;
}

std::string Player::getTeam()
{
	return team;
}

int Player::getPoints()
{
	return wmPoints;
}

int Player::getConstructorPoints()
{
	return constructorsPoints;
}

void Player::setDiff(int p)
{
	diff = p;
}

int Player::getDiff()
{
	return diff;
}

void Player::addWins()
{
	wins = wins + 1;
}

int Player::getWins()
{
	return wins;
}

//to score the race result
void Player::addPoints(int pt)
{
	wmPoints += pt;
}

void Player::addConstructors(int pkt)
{
	constructorsPoints += pkt;
}

