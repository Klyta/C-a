#pragma once
#include <string>
#include "LandScape.h"
#include<iostream>
#include "Bonus.h"
#include <map>
#include "Player.h"
#include "Cell.h"
#include "Unit_type.h"
#include "GameObj.h"
class Unit: public GameObj
{
	virtual std::string getName();
	//std::string Name;
	//std::string unit_type;
	bool Deaf = 0;
	int Health;
	int Demage;
	//std::string unitProfesion[2]{"M","C"};
	//std::string unitElement[3] = {"L","A","N"};
protected:
	Player& player;
	std::map <LandScape, Bonus> AttackBonus;
	const Cell* cell;
public:
	void move(Cell*);
	std::string toString();
	//void unitLoad();
	void setHealth(int& health);
	void setDemage(int &demege);
	int& getDemage();
   // std::string& getName();
	int& getHealth();
	Player& getPlayer() const;
	void setDeaf();
	bool getDeaf();
	virtual std::map<std::string, int > getMap()=0;
	Unit(int Health, int Demage, const Cell *cell, Player& player);
	virtual void getAttackBonus();
	void attack(Unit& unitD);
	virtual ~Unit();
	const Cell* getUnitCell();
	std::string getUnit_type();
};
