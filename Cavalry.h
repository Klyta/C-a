#pragma once
#include "Unit.h"
#include "Cell.h"
#include <map>
#include "LandScape.h"
#include "Bonus.h"
class Cavalry : public Unit
{
public:
	std::map<std::string, int> getMap();
	static std::map<std::string, int> CBonus;
	std::string getName();
	Cavalry(int Health, int Demage, const Cell *cell, Player& player);
	~Cavalry();
};
