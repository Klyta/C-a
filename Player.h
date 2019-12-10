#pragma once
#include <string>
#include "vector"
#include "GameObj.h"
class Player
{
   std::stack<GameObj*>  playerObj;
   const int number;
public:
	Player(int number);
	int GetPlayerNumber();
	void SaveGame() const;
	void SaveObj(GameObj* obj);
	void Load();
	std::string LoadStr();
};

