#include "Cavalry.h"
#include "Cell.h"
#include "iostream"
#include "string"
#include <map>
#include "LandScape.h"
#include "Bonus.h"
std::map<std::string, int> Cavalry::CBonus = { {"forest",10}, {"pound",-10} };
Cavalry::Cavalry(int Health, int Demage, const Cell *cell, Player& player) : Unit(Health, Demage, cell, player)
{
	std::cout << "Cavalry(int,int)" << std::endl;

}
 std::map<std::string, int>Cavalry::getMap()
{
	return Cavalry::CBonus;
}
 std::string Cavalry::getName()
 {
	 std::string Name;
	 Name = "C";
	 std::cout << "getName-C" << std::endl;
	 return Name;
 }

Cavalry::~Cavalry()
{
	std::cout << "~Cavalry::Cavalry()" << std::endl;
}