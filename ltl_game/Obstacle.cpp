#include <iostream>

#include "Obstacle.h"


Obstacle::Obstacle(int upperBoarder, int lowerBoarder, int distanceX)
{
	this->mUpperBoarder = upperBoarder;
	this->mLowerBoarder = lowerBoarder;
	this->mDistanceX = distanceX;
}
Obstacle::Obstacle()
{

}
Obstacle::~Obstacle()
{
	//std::cout << "Obstacle deleted!! : " << mUpperBoarder << " | " << mLowerBoarder << " | " << mDistanceX;
}

