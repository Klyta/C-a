include "Player.h"
#include "fstream"
#include "CavalryFactory.h"
#include "Cell.h"
Player::Player(int number): number(number)
{
	std::cout << "Player()" << std::endl;
}
int FromStrToNumber(char str[],int size)// char
{
	int number = 0;
	for (int i=0; i <size; i++)
	{
		int digit = 0;
		digit = (int)str[i] - (int) '0';
		number = number * 10 + digit;
	}
	return number;
}
int FromStrToNumber(std::string str)// string
{
	int number = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int digit = 0;
		digit = (int)str[i] - (int) '0';
		number = number * 10 + digit;
	}
	return number;
}
void Player::SaveGame() 
{
	if (playerObj.empty())
	{
		std::cout << "Eror,steck is empty" << std::endl;
	}
	std::string str;
	std::ofstream ou;
	ou.open("Output.txt");
	if (ou.is_open())
	{
		std::cout << "Ok!" << std::endl;
	}
	else
	{
		std::cout << "Something wrong!" << std::endl;
	}
	for (int i = 0; i < playerObj.size(); i++)
	{
		str = playerObj.top()->toString();
	 ou << str <<" ";
	//	std::cout << "Save Game -" << std::endl;
		playerObj.pop();
	}
	std::cout << "Save - " << str << std::endl;
	ou.close();
}
int Player::GetPlayerNumber()
{
	return number;
}
void Player::SaveObj(GameObj* obj)
{
	playerObj.push(obj);
}
void Player::Load()
{
	std::ifstream ou;
	ou.open("Output.txt");
	if (ou.is_open())
	{
		std::cout << "Ok!" << std::endl;
	}
	else
	{
		std::cout << "Something wrong!" << std::endl;
	}
	std::string str;
	//ou >> str;
	getline(ou, str);
	int i = 0;
	{
		if (str[i] == 'U' && str[i + 1] == 'C')       //C
		{
			std::cout << "Cav";
			int playerNum = 0;
			int Damege = 0;
			int Health = 0;
			int x = 0;
			int y = 0;
			std::string T;
			while (str[i] != ';')
			{
				playerNum = FromStrToNumber(&str[i], 1);
				i++;
			}
			if (playerNum == 0)
			{
				std::cout << "Eror in load(p.n.)";
			}
			else
			{
				std::cout << playerNum;
			}
			while (str[i] != 'H')
			{
				i++;
			}
			std::string strx;
			i++;
			while (str[i] != ';')
			{

				strx += std::to_string(FromStrToNumber(&str[i], 1));
				i++;
			}
			Health = FromStrToNumber(strx) ;
			std::cout << "H = " << Health ;
			while (str[i] != 'D')
			{
				i++;
			}
			std::string stry;
			i++;
			while (str[i] != ';')
			{

				stry += std::to_string(FromStrToNumber(&str[i], 1));
				i++;
			}
			Damege = FromStrToNumber(stry);
			std::cout << "D = " << Damege ;
			while (str[i] != ':')
			{
				i++;
			}
			while (str[i] != ';')
			{
				//strx = std::to_string(str[i]);
				x = FromStrToNumber(&str[i], 1);
				i++;
			}
			//x = FromStrToNumber(strx);
			std::cout << "X = " << x << std::endl;

			while (str[i] != ':')
			{
				i++;
			}
			while (str[i] != ';')
			{

				y = FromStrToNumber(&str[i], 1);
				i++;
			}

			std::cout << "Y = " << y << std::endl;

			while (str[i] != ':')
			{
				i++;
			}
			while (str[i + 1] != '/')
			{

				T += str[i + 1];
				i++;
			}

			std::cout << "T = " << T << std::endl;
			Cell cell(T, y, x);
			Cavalry* c = new Cavalry(Health,Damege,&cell, this);
			std::cout << "Unit c" << std::endl;
			std::cout << "H-  " << c->getHealth() << "D-  " << c->getDemage() << "P-  " << c->getPlayer().GetPlayerNumber() << c->getUnitCell()->getOllData() << std::endl;
		}
		if (str[i]=='U' && str[i+1] == 'B')       //B
		{
			std::cout << "Bild";
		}
		if (str[i] == 'F' && str[i + 1] == 'C')        //FC
		{
			std::cout << "CavFac";

			int playerNum = 0;
			int x = 0;
			int y = 0;
			std::string T;

			while (str[i] != ';')
			{
				playerNum = FromStrToNumber(&str[i], 1);
				i++;
			}
			if (playerNum == 0)
			{
				std::cout << "Eror in load(p.n.)";
			}
			else
			{
				std::cout << playerNum;
			}
			//while (str[i] == 'x' && str[i+1]==':')
			//{
			//	i++;
			//}

			std::string strx;
			//while (str[i] == 'x' && str[i+1] == ':')
			//{
			//	i++;
			//}
			//        while (str[i] != ';')
			//		{
			//			x = FromStrToNumber(&str[i], 1);
			//std::cout << "Strx = " << strx;
			//			i++;
			//		}
			while (str[i] != ':')
			{
				i++;
			}
			while (str[i] != ';')
			{
				//strx = std::to_string(str[i]);
				x = FromStrToNumber(&str[i], 1);
				i++;
			}
			//x = FromStrToNumber(strx);
			std::cout << "X = " << x << std::endl;

			while (str[i] != ':')
			{
				i++;
			}
			while (str[i] != ';')
			{

				y = FromStrToNumber(&str[i], 1);
				i++;
			}

			std::cout << "Y = " << y << std::endl;

			while (str[i] != ':')
			{
				i++;
			}
			while (str[i + 1] != '/')
			{

				T += str[i + 1];
				i++;
			}

			std::cout << "T = " << T << std::endl;
			Cell cell(T, y, x);
			CavalryFactory* cFactoryPtr = new CavalryFactory(cell, this);
			std::cout << "Factory F" << std::endl;
		}
		else
		{
			std::cout << "Eror in load" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Load - " << str << std::endl;
		ou.close();
	}
}
