#pragma once
#include <string>
#include <vector>
class Cell
{
	int x = 5;
	int y = 5;
	std::string LandScapeT;
public:
    std::string getCellType() const;
	int getCellPositionx() const;
	int getCellPositiony() const;
	Cell(std::string,int,int);
	std::string getOllData() const;
	~Cell();
};