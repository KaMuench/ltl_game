#pragma once

class Obstacle
{
private:
	int mUpperBoarder = 0;
	int mLowerBoarder = 0;
	int mDistanceX = 0;

public:
	Obstacle(int,int,int);
	Obstacle();
	~Obstacle();

	void setUpperBoarder(int upperBoarder)
	{
		this->mUpperBoarder = upperBoarder;
	}
	void setLowerBoarder(int lowerBoarder)
	{
		this->mLowerBoarder = lowerBoarder;
	}
	void setDistanceX(int distanceX)
	{
		this->mDistanceX = distanceX;
	}
	int getUpperBoarder()
	{
		return this->mUpperBoarder;
	}
	int getLowerBoarder()
	{
		return this->mLowerBoarder;
	}
	int getDistanceX()
	{
		return this->mDistanceX;
	}
};
