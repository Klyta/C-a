#pragma once
#include "Unit.h"
#include "CavalryFactory.h"
#include <map>
#include <string>
class Builder :public Unit
{
public:	
	~Builder();
	Builder(int Health, int Demage, Cell *cell, Player& player);
	std::map<std::string, int> getMap();
	CavalryFactory* bildFactory();
	static std::map<std::string, int> BuildBonus;
	std::string getName();
};

