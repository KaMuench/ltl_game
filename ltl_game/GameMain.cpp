#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

#include "Obstacle.h"
#include "Player.h"

class Game
{

public:
	const int GAME_HEIGTH = 20;
	const int GAME_WIDTH = 80;
	Obstacle obstacles[7];
	Player* player = new Player(GAME_HEIGTH, 10);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD caret;
	int obstaclesPassed = 0;
	const int VERY_FAST = 5;
	const int FAST = 10;
	const int MEDIUM = 20;
	const int SLOW = 40;
	int speed;

	void resetPlayer()
	{
		player->setPositionY(GAME_HEIGTH / 2);
	}

	void displayPoints()
	{
		caret.Y = 25;
		caret.X = 18;
		SetConsoleCursorPosition(hOut, caret);
		std::cout << obstaclesPassed;
	}

	void movePlayer()
	{

		if (GetKeyState(VK_UP) & 0x8000)
		{
			SetConsoleCursorPosition(hOut, player->getLocation());
			std::cout << " ";
			player->setPositionY(player->getPositionY() - 1);
		}
		else if (GetKeyState(VK_DOWN) & 0x8000)
		{
			SetConsoleCursorPosition(hOut, player->getLocation());
			std::cout << " ";
			player->setPositionY(player->getPositionY() + 1);
		}
	}

	void createRandObstacles()
	{
		obstacles[0].setDistanceX(40 + std::rand() % (30 - 10));
		obstacles[0].setUpperBoarder(3 + std::rand() % (13 - 3));
		obstacles[0].setLowerBoarder(obstacles[0].getUpperBoarder() + 3 + std::rand() % (13 - 3));

		for (int i = 1; i < 7; i++)
		{
			obstacles[i].setDistanceX(10 + std::rand() % (30 - 10));
			obstacles[i].setUpperBoarder(3 + std::rand() % (13 - 3));
			obstacles[i].setLowerBoarder(obstacles[i].getUpperBoarder() + 3 + std::rand() % (13 - 3));
		}
	}

	void displayLVL()
	{
		for (int i = 0; i < GAME_HEIGTH; i++)
		{
			caret.Y = i;
			caret.X = 0;
			for (int j = 0; j < 7; j++)
			{
				if (caret.X + obstacles[j].getDistanceX() <= GAME_WIDTH)
				{						
					caret.X += obstacles[j].getDistanceX();
					SetConsoleCursorPosition(hOut, caret);

					if (i <= obstacles[j].getUpperBoarder() || i >= obstacles[j].getLowerBoarder())
					{

						std::cout << "#";
						caret.X++;
						SetConsoleCursorPosition(hOut, caret);
						std::cout << " ";
						caret.X--;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

	boolean calcHit() 
	{
		if (player->getPositionX() == obstacles[0].getDistanceX()) 
		{
			obstaclesPassed++;
			displayPoints();
			if (player->getPositionY() <= obstacles[0].getUpperBoarder() || player->getPositionY() >= obstacles[0].getLowerBoarder())
			{
				return true;
			}
		}
		return false;
	}

	void displayPlayer()
	{
		SetConsoleCursorPosition(hOut, player->getLocation());
		std::cout << "*";
	}

	void nextFrame()
	{
		if(obstacles[0].getDistanceX()>0)
		obstacles[0].setDistanceX(obstacles[0].getDistanceX() - 1);
		else
		{
			for (int i = 1; i < 7; i++) {
				obstacles[i - 1] = obstacles[i];
			}
			Obstacle temp;
			temp.setDistanceX(10 + std::rand() % (30 - 10));
			temp.setUpperBoarder(3 + std::rand() % (13 - 3));
			temp.setLowerBoarder(temp.getUpperBoarder() + 3 + std::rand() % (13 - 3));
			obstacles[6] = temp;
		}
		displayLVL();
		displayPlayer();
	}
};


	int main()
	{
		Game game;
		COORD temp;
		boolean play = false;


		std::cout << "Welcome to the Game!!" << std::endl;
		std::cout << "Please select level of difficulty or press (ESCAPE) to leave." << std::endl;
		std::cout << "Press   F1    for    VERY FAST\n";
		std::cout << "Press   F2    for    FAST\n";
		std::cout << "Press   F3    for    MEDIUM\n";
		std::cout << "Press   F4    for    SLOW\n";

		while (true)
		{
			if (GetKeyState(VK_ESCAPE) & 0x8000)
			{
				break;
			} 
			else if (GetKeyState(VK_F1) & 0x8000)
			{
				game.speed = game.VERY_FAST;
				play = true;
			}
			else if (GetKeyState(VK_F2) & 0x8000)
			{
				game.speed = game.FAST;
				play = true;
			}
			else if (GetKeyState(VK_F3) & 0x8000)
			{
				game.speed = game.MEDIUM;
				play = true;
			}
			else if(GetKeyState(VK_F4) & 0x8000)
			{
				game.speed = game.SLOW;
				play = true;
			}


			if (play)
			{		

				system("cls");
				srand(time(NULL));

				game.createRandObstacles();
				game.displayLVL();
				game.displayPlayer();

				temp.Y = 25;
				temp.X = 0;
				SetConsoleCursorPosition(game.hOut, temp);
				std::cout << "Obstacles passed: ";
				while (true)
				{		
					Sleep(game.speed);
					game.movePlayer();
					game.nextFrame();
					if (game.calcHit())
							break;

				}
				system("cls");
				temp.Y = 0;
				temp.X = 0;
				SetConsoleCursorPosition(game.hOut, temp);
				std::cout << "GAME OVER \n";
				std::cout << "Score: " << game.obstaclesPassed << std::endl;
				std::cout << "Please select level of difficulty or press (ESCAPE) to leave." << std::endl;
				std::cout << "Press   F1    for    VERY FAST\n";
				std::cout << "Press   F2    for    FAST\n";
				std::cout << "Press   F3    for    MEDIUM\n";
				std::cout << "Press   F4    for    SLOW\n";
				game.obstaclesPassed = 0;
				play = false;
				game.resetPlayer();
			} 

		}


		system("pause");
		return 0;
	}