
#include "Factory.h"
#include "Unit.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>
Factory::Factory(const Cell& cell,Player& player):cell(cell), player(player)
{
	std::cout << "Factory::Factory(Cell)" << std::endl;
}
Player& Factory::getPlayer() const
{
	return player;
}
 const Cell* Factory::getFactoryCell() const
{
	const Cell* c = & cell;
	return c;
}
Factory::~Factory()
{
	std::cout << "Factory::~Factory()" << std::endl;
	std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
}
std::string Factory::getFactoryType()
{
	std::string str;
	str = "F";
	return str;
}
Unit* Factory::getUnit(const std::string& unitType)
{
	Unit* unit = nullptr;
	std::vector<Factory*>::iterator iter = departments.begin();
	while (unit == nullptr && iter != departments.end())
	{
		unit = (*iter)->getUnit(unitType);
		++iter;
	}
	
	return unit;
}
std::string Factory::toString() 
{
	std::string str = "F" + getFactoryType() +std::to_string(getPlayer().GetPlayerNumber()) +";"+ getFactoryCell()->getOllData()+"/";
	std::cout << "GOFbj toString() "<< str << std::endl;
	return str;
}