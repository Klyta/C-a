#pragma once
#include "Factory.h"
#include "Unit.h"
#include "Player.h"
#include <string>
#include "Cavalry.h"

class CavalryFactory : public Factory
{
   public:
	CavalryFactory(const Cell& cell, Player& player);
	~CavalryFactory();
	std::string getFactoryType();
	Cavalry* getUnit(const std::string& unitType);
};

