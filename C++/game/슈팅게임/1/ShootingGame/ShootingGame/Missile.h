#pragma once

class Missile
{
private:
	int x;
	int y;

	bool bMoveLeft;

public:
	void setMissile(int _y);

	void moveMissile();
	void drawMissile();

	bool checkEnd();

	bool checkCollider(int _x, int _y);

	int getX();
	int getY();
};
