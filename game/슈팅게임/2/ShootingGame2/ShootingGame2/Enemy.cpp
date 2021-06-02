#include "Enemy.h"
#include "Console.h"
#include "EnemyMissile4.h"

#include <iostream>
using namespace std;

void Enemy::setEnemy()
{
	x = rand() % 20;
	y = 0;
	enemyCanShoot = 0;
}

void Enemy::drawEnemy()
{
	gotoXY(x, y);

	setTextColor(4);
	cout << "¡å";
	setTextColor(15);

	y++;	//move
}

bool Enemy::checkEnd()
{
	if (y > 39)
	{
		return true;
	}

	return false;
}

int Enemy::getX()
{
	return x;
}

int Enemy::getY()
{
	return y;
}

int Enemy::getEnemyCanShoot()
{
	return enemyCanShoot;
}

void Enemy::setEnemyCanShoot(int value)
{
	enemyCanShoot = value;
}

void Enemy::shoot(EnemyMissile* missile)
{
	missile->setEnemyMissile(x, y);
}