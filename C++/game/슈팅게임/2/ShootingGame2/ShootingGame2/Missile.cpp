#include "Missile.h"
#include "Console.h"

#include <iostream>
using namespace std;

void Missile::setMissile(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Missile::drawMissile()
{
	gotoXY(x, y);

	setTextColor(2);
	cout << "¡Ü";
	setTextColor(15);

	y--;	//move
}

bool Missile::checkEnd()
{
	if (y < 0)
	{
		return true;
	}

	return false;
}

bool Missile::checkCollision(int _x, int _y)
{
	if (x == _x && (y + 1== _y || y + 2 == _y))
	{
		return true;
	}

	return false;
}

int Missile::getX()
{
	return x;
}

int Missile::getY()
{
	return y;
}