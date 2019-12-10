#include "Cell.h"
#include <string>
Cell::Cell(std::string Type, int x, int y) : LandScapeT(Type), x(x), y(y)
{
}
std::string Cell::getCellType() const
{
	return  LandScapeT;
}
int Cell::getCellPositionx() const
{
	return y;
}
int Cell::getCellPositiony() const
{
	return x;
}
std::string Cell::getOllData() const
{
	std::string fData ="x:" + std::to_string(getCellPositionx()) + 
		";" + "y:" + std::to_string(getCellPositiony()) + ";"+"T:" + getCellType();
	return(fData);
}
Cell::~Cell()
{
}
