#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

#define UP		72
#define LEFT	75
#define RIGHT	77
#define DOWN	80

using namespace std;


void gotoxy(int x, int y);
void displayScreen();
void move(int dir);


int currentX, currentY;

int randomX[10] = { 0, };
int randomY[10] = { 0, };

char ShowMap[20][21] = {
	"++++++++++++++++++++",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"+..................+",
	"++++++++++++++++++++",
};

int main()
{
	srand((unsigned)time(NULL));

	int ch;

	bool bCheck = true;

	currentX = 2;
	currentY = 2;

	for (int i = 0; i < 10; i++)
	{
		do {
			bCheck = false;

			randomX[i] = rand() % 17 + 1;

			if (i != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (randomX[i] == randomX[j])
					{
						bCheck = true;
					}
					else
					{
						bCheck = false;
					}
				}
			}


		} while (bCheck);
	}

	for (int i = 0; i < 10; i++)
	{
		do {
			bCheck = false;

			randomY[i] = rand() % 18 + 1;

			if (i != 0)
			{
				for (int j = 0; j < i; j++)
				{
					if (randomY[i] == randomY[j])
					{
						bCheck = true;
					}
					else
					{
						bCheck = false;
					}
				}
			}


		} while (bCheck);
	}

	for (int i = 0; i < 10; i++)
	{
		ShowMap[randomX[i]][randomY[i]] = '+';
	}



	while (true)
	{
		displayScreen();
		ch = _getch();

		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();
			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);
				break;
			}
		}
		else
		{
			ch = tolower(ch);
			if (ch == 'q')
			{
				exit(0);
			}
			else if (ch == 'z')
			{
				ShowMap[currentY][currentX] = 'X';
			}
			else if (ch == 'a')
			{
				//주변 + 없애기
				ShowMap[currentY + 1][currentX] = '.';
				ShowMap[currentY - 1][currentX] = '.';
				ShowMap[currentY][currentX + 1] = '.';
				ShowMap[currentY][currentX - 1] = '.';

				//테두리 + 다시 만들기
				for (int i = 0; i < 20; i++)
				{
					ShowMap[0][i] = '+';
					ShowMap[19][i] = '+';
					ShowMap[i][0] = '+';
					ShowMap[i][19] = '+';
				}
			}

		}
	}
	return 0;
}

void gotoxy(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void displayScreen()
{
	for (int y = 0; y < 20; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			gotoxy(x, y);
			_putch(ShowMap[y][x]);
		}
	}

	gotoxy(currentX, currentY);
	_putch('0');
	gotoxy(25, 2);
	cout << "Q : 종료";

}

void move(int dir)
{
	int dir_x = 0, dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}

	if (ShowMap[currentY + dir_y][currentX + dir_x] != '+')
	{
		currentX += dir_x;
		currentY += dir_y;
	}
}