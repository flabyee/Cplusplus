#include <iostream>
#include <time.h>
#include <vector>

#include "Console.h"
#include "Enemy.h"
#include "Missile.h"
#include "EnemyMissile4.h"


#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

using namespace std;

int x, y;

vector<Enemy> enemies;
vector<Missile> missiles;
vector<EnemyMissile> enemyMissiles;

void setConsoleView()
{
	system("mode con:cols=40 lines=40");
	system("title SHOOTING GAME #2");
}

void initData()
{
	srand((unsigned)time(NULL));

	x = 10;
	y = 38;

	enemies.clear();
	missiles.clear();
}

void checkDir()
{
	int key = _getch();
	switch (key)
	{
	case UP:
		if (y > 0) y--;
		break;
	case DOWN:
		if (y < 38)y++;
		break;
	case LEFT:
		if (x > 0) x--;
		break;
	case RIGHT:
		if (x < 19)x++;
		break;
	}

}

void checkCollision()
{
	//myMissile - Enemy

	bool bCol = false;
	do 
	{
		bCol = false;

		for (int i = 0; i < missiles.size(); i++)
		{
			for (int j = 0; j < enemies.size(); j++)
			{
				if (missiles[i].checkCollision(enemies[j].getX(), enemies[j].getY()))
				{
					missiles.erase(missiles.begin() + i);
					enemies.erase(enemies.begin() + j);

					bCol = true;
					break;

				}
			}
			if (bCol)
			{
				break;
			}
		}
	} while (bCol);
}

void checkCollision2()
{
	//EnemyMissile - MyMisslie

	bool bCol = false;

	do
	{
		bCol = false;

		for (int i = 0; i < enemyMissiles.size(); i++)
		{
			for (int j = 0; j < missiles.size(); j++)
			{
				if (enemyMissiles[i].checkColMyMissile(missiles[j].getX(), missiles[j].getY()))
				{
					enemyMissiles.erase(enemyMissiles.begin() + i);
					missiles.erase(missiles.begin() + j);

					bCol = true;
					break;

				}
			}
			if (bCol)
			{
				break;
			}
		}
	} while (bCol);
}


void drawPlayer()
{
	gotoXY(x, y);
	cout << "бу";
	
	gotoXY(19, 39);
}

int main()
{
	setConsoleView();

	initData();

	int canShoot = 0;

	bool bEnd = false;

	while (true)
	{
		int key = getKeyDown();
		key = tolower(key);

		if (key == 0xE0)
		{
			checkDir();
		}
		else if (key == 'a' && canShoot <= 0)
		{
			Missile missile;
			missile.setMissile(x, y);

			missiles.push_back(missile);

			canShoot = 3;
		}

		if (rand() % 100 < 10)
		{
			Enemy enemy;
			enemy.setEnemy();

			enemies.push_back(enemy);
		}


		checkCollision();
		checkCollision2();
		//EnemyMissile - Player
		for (int i = 0; i < enemyMissiles.size(); i++)
		{
			if (enemyMissiles[i].checkColPlayer(x, y))
			{
				bEnd = true;
				break;

			}
		}
		if (bEnd)
		{
			break;
		}

		//enemyShoot
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].getEnemyCanShoot() == 0)
			{
				EnemyMissile enemyMissile;
				enemies[i].shoot(&enemyMissile);
				enemyMissiles.push_back(enemyMissile);

				enemies[i].setEnemyCanShoot(15);
			}
			
		}

		//draw
		for (int i = 0; i < missiles.size(); i++)
		{
			missiles[i].drawMissile();
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].drawEnemy();
		}
		for (int i = 0; i < enemyMissiles.size(); i++)
		{
			enemyMissiles[i].drawEnemyMissile();
		}

		//checkEnd
		for (int i = 0; i < missiles.size(); i++)
		{
			if (missiles[i].checkEnd())
			{
				missiles.erase(missiles.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].checkEnd())
			{
				enemies.erase(enemies.begin() + i);
				i--;
			}
		}
		for (int i = 0; i < enemyMissiles.size(); i++)
		{
			if (enemyMissiles[i].checkEnd())
			{
				enemyMissiles.erase(enemyMissiles.begin() + i);
				i--;
			}
		}




		



		drawPlayer();

		Sleep(100);
		clrscr();

		canShoot--;
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i].getEnemyCanShoot() > 0)
			{
				enemies[i].setEnemyCanShoot(enemies[i].getEnemyCanShoot() - 1);
			}
		}
		
	}

	clrscr();
	gotoXY(7, 10);
	cout << "GAME OVER" << endl << endl << endl << endl << endl << endl << endl;

	return 0;
}