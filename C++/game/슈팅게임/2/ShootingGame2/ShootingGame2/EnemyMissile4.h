#pragma once

class EnemyMissile
{
private:
	int x;
	int y;

public:
	void setEnemyMissile(int _x, int _y);
	void drawEnemyMissile();
	bool checkEnd();

	bool checkColMyMissile(int _x, int _y);
	bool checkColPlayer(int _x, int _y);
};
