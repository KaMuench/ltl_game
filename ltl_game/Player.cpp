#include "Player.h"

Player::Player(int GAME_HEIGTH, int positionX)
{
	this->mPlayerLocation.Y = GAME_HEIGTH / 2;
	this->mPlayerLocation.X = positionX;
}

Player::~Player()
{

}