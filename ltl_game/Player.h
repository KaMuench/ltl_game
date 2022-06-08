#pragma once
#include <windows.h>
class Player
{
private:
	COORD mPlayerLocation;
public:
	Player(int, int);
	~Player();

	void setPositionY(int positionY)
	{
		this->mPlayerLocation.Y = positionY;
	}
	int getPositionY()
	{
		return this->mPlayerLocation.Y;
	}
	void setPositionX(int positionX)
	{
		this->mPlayerLocation.X = positionX;
	}
	int getPositionX()
	{
		return this->mPlayerLocation.X;
	}
	COORD getLocation()
	{
		return this->mPlayerLocation;
	}
};