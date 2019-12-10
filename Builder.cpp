#include "Builder.h"
#include<iostream>
#include"CavalryFactory.h"
#include <map>

std::map<std::string, int> Builder::BuildBonus = { {"forest",10}, {"pound",-10} };

Builder::~Builder()
{
	std::cout << "~Builder" << std::endl;
}
std::map<std::string, int> Builder::getMap()
{
	return Builder::BuildBonus;

}

Builder::Builder(int Health, int Demage, Cell *cell, Player& player) : Unit(Health, Demage, cell, player)
{
	std::cout << "Bilder(int,int)" << std::endl;

}
std::string Builder::getName()
{
	std::string Name;
	Name = "B";
	std::cout << "getName-B" << std::endl;
	return Name;
}
CavalryFactory* Builder::bildFactory()
{
	CavalryFactory* cFactoryPtr = new CavalryFactory(*getUnitCell(),getPlayer());
	std::cout << "Factory F" << std::endl;
    getPlayer().SaveObj(cFactoryPtr);
	return cFactoryPtr;
}