#pragma once
#include "Unit.h"
#include <string>
#include <vector>
#include "Cell.h"
#include "Player.h"
#include "GameObj.h"
class Factory : public GameObj
{
protected:
Player& player;
public:
	Factory(const Cell& cell,Player& player);
	const Cell* getFactoryCell() const;
	virtual ~Factory();
	virtual std::string getFactoryType();
	virtual Unit* getUnit(const std::string&) ;
	std::string toString();
    Player& getPlayer() const;
	
private:
	const Cell& cell;
	std::vector<Factory*> departments;
};