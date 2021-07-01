#include "EnemyMissile4.h"
#include "Console.h"

#include <iostream>
using namespace std;

void EnemyMissile::setEnemyMissile(int _x, int _y)
{
	x = _x;
	y = _y;
}

void EnemyMissile::drawEnemyMissile()
{
	gotoXY(x, y);
	setTextColor(5);
	cout << "¡Ü";
	setTextColor(15);

	y++;
	y++;
}

bool EnemyMissile::checkEnd()
{
	if (y > 39)
	{
		return true;
	}

	return false;
}

bool EnemyMissile::checkColMyMissile(int _x, int _y)
{
	if (x == _x && (y == _y || y - 1 == _y || y - 2 == _y)) //)
	{
		return true;
	}

	return false;
}

bool EnemyMissile::checkColPlayer(int _x, int _y)
{
	if (x == _x && (y == _y || y - 1 == _y || y - 2 == _y))
	{
		return true;
	}

	return false;
}
