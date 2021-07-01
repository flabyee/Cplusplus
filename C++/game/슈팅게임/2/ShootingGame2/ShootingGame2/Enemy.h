#pragma once

#include "EnemyMissile4.h"

class Enemy
{
private:
	int x;
	int y;
	int enemyCanShoot;
public:
	void setEnemy();
	void drawEnemy();
	bool checkEnd();
	
	int getX();
	int getY();
	int getEnemyCanShoot();
	void setEnemyCanShoot(int value);

	void shoot(EnemyMissile* missile);
};